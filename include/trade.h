/*
** TRADE PROJECT, 2024
** trade
** File description:
** trade
*/

static const int SUCCESS = 0;
static const int FAILURE = 84;

#pragma once

typedef struct trade_s {
    size_t timebank;
    size_t time_per_move;
    size_t candle_interval;
    char *candle_format;
    size_t candles_total;
    size_t candles_given;
    size_t initial_stack;
    float transaction_fee;
} trade_t;
