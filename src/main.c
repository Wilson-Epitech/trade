/*
** TRADE PROJECT, 2024
** trade
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "trade.h"

static void get_format_position(settings_t *settings, char *str)
{
    char **array = word_array_delim(str, ",");
    size_t i = 0;

    while (array[i] != NULL) {
        if (strncmp(array[i], "pair", 4) == 0)
            settings->candle_format.pair_position = i;
        if (strncmp(array[i], "date", 4) == 0)
            settings->candle_format.date_position = i;
        if (strncmp(array[i], "high", 4) == 0)
            settings->candle_format.high_position = i;
        if (strncmp(array[i], "low", 3) == 0)
            settings->candle_format.low_position = i;
        if (strncmp(array[i], "open", 4) == 0)
            settings->candle_format.open_position = i;
        if (strncmp(array[i], "close", 5) == 0)
            settings->candle_format.close_position = i;
        if (strncmp(array[i], "volume", 6) == 0)
            settings->candle_format.volume_position = i;
        i += 1;
    }
}

static void get_settings(settings_t *settings, char **array)
{
    if (strcmp(array[1], "timebank") == 0)
        settings->timebank = atoi(array[2]);
    if (strcmp(array[1], "time_per_move") == 0)
        settings->time_per_move = atoi(array[2]);
    if (strcmp(array[1], "candle_interval") == 0)
        settings->candle_interval = atoi(array[2]);
    if (strcmp(array[1], "candle_format") == 0) {
        settings->candle_format.candle_str = strdup(array[2]);
        get_format_position(settings, settings->candle_format.candle_str);
    }
    if (strcmp(array[1], "candles_total") == 0)
        settings->candles_total = atoi(array[2]);
    if (strcmp(array[1], "candles_given") == 0)
        settings->candles_given = atoi(array[2]);
    if (strcmp(array[1], "initial_stack") == 0)
        settings->initial_stack = atoi(array[2]);
    if (strcmp(array[1], "transaction_fee_percent") == 0)
        settings->transaction_fee = atof(array[2]);
    return;
}

static int action(settings_t *settings, candle_t *candle,
    trade_t *trade, char **array)
{
    double simulate = 0;

    if (strncmp(trade->buffer, "update game next_candles", 24) == 0) {
        array = word_array_delim(trade->buffer, " ");
        trade->splited = word_array_delim(array[3], ",");
        candle->close =
            atof(trade->splited[settings->candle_format.close_position]);
    }
    if (strncmp(trade->buffer, "action order", 12) == 0) {
        if (settings->initial_stack == 0)
            return NOTHING;
        trade->buy_quantity = settings->initial_stack / candle->close;
        trade->stack_after = trade->buy_quantity * candle->close;
        simulate = settings->initial_stack - trade->stack_after;
        if (simulate < 0)
            return NOTHING;
        return BUY;
    }
    return 0;
}

static void send_to_sever(settings_t *settings,
    trade_t *trade, candle_t *candle)
{
    char **array = NULL;
    int result = action(settings, candle, trade, array);

    if (result == NOTHING) {
        fprintf(stdout, "no_moves\n");
        fflush(stdout);
        return;
    }
    if (result == BUY) {
        printf("buy USDT_BTC %.8f\n", trade->buy_quantity);
        fflush(stdout);
        settings->initial_stack -= trade->stack_after;
        return;
    }
}

static int bot_loop(settings_t *settings, trade_t *trade, candle_t *candle)
{
    char **array = NULL;

    while (1) {
        if (getline(&trade->buffer, &trade->size_buffer, stdin) == -1) {
            free(trade->buffer);
            fprintf(stderr, "getline failed\n");
            return FAILURE;
        }
        if (strncmp(trade->buffer, "settings", 8) == 0) {
            array = word_array_delim(trade->buffer, " ");
            get_settings(settings, array);
        }
        fprintf(stderr, "buffer : %s", trade->buffer);
        send_to_sever(settings, trade, candle);
    }
    return SUCCESS;
}

/// This is the main
int main(void)
{
    settings_t *settings = malloc(sizeof(settings_t));
    trade_t *trade = malloc(sizeof(trade_t));
    candle_t *candle = malloc(sizeof(candle_t));

    if (settings == NULL)
        return FAILURE;
    if (trade == NULL)
        return FAILURE;
    if (candle == NULL)
        return FAILURE;
    memset(settings, 0, sizeof(settings_t));
    memset(trade, 0, sizeof(trade_t));
    memset(candle, 0, sizeof(candle_t));
    trade->buffer = malloc(sizeof(char) * trade->size_buffer);
    if (trade->buffer == NULL)
        return FAILURE;
    if (bot_loop(settings, trade, candle) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
