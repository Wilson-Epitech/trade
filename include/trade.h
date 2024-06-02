/*
** TRADE PROJECT, 2024
** trade
** File description:
** trade
*/

/** @brief This return value
 * representing the `success`
 * of the program or function
*/
static const int SUCCESS = 0;

/** @brief This return value
 * representing the `failure`
 * of the program or function
*/
static const int FAILURE = 84;

/** @brief This return value
 * representing the `buy` action
*/
static const int BUY = 2;

/** @brief This return value
 * representing the `nothing` action
*/
static const int NOTHING = 1;

/** @brief This return value
 * representing the `sell` action
*/
static const int SELL = -1;

#pragma once

typedef struct trade_s {
    double *candles_rsi;
    char *buffer;
    char **splited;
    size_t size_buffer;
    double stack_after;
    double buy_quantity;
} trade_t;

typedef struct candle_format_s {
    char *candle_str;
    int pair_position;
    int date_position;
    int high_position;
    int low_position;
    int open_position;
    int close_position;
    int volume_position;
} candle_format_t;

typedef struct settings_s {
    size_t timebank;
    size_t time_per_move;
    size_t candle_interval;
    size_t candles_total;
    size_t candles_given;
    candle_format_t candle_format;
    double initial_stack;
    double transaction_fee;
} settings_t;

typedef struct candle_s {
    double date;
    double high;
    double low;
    double open;
    double close;
    double volume;
} candle_t;

//-------word_array.c -----------------------------------//
char **word_array_delim(char const *str, char *separators);
