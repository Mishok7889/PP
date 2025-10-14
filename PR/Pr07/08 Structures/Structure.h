#pragma once
#include <cstdint>

// 1. Collection
struct Collection
{
    char _chr1;
    const char* _pc;
    char _chr2;
    short int _si;
    float _f;
    char _chr3;
    double _d;
};

// 2. Structures

struct Complex
{
    double _re;
    double _im;
};

inline void f(Complex z1, Complex z2)
{
    z1._re = z2._re;
    z1._im = z2._im;
    return;
}

inline void g(Complex& z1, Complex& z2)
{
    z1._re = z2._re;
    z1._im = z2._im;
    return;
}

struct BuiltInIntArray
{
    int* _k;
};

struct BuiltInDoubleArray
{
    double* _d;
};

// 4. Bit fields

enum Week
{
    monday = 1, tuesday, wednesday, thursday, friday, saturday, sunday
};

struct DayStatusLong
{
    unsigned short _date;
    unsigned short _month;
    Week _day;
    unsigned short _holiday;
};

struct DayStatus
{
    unsigned short _date : 4;
    unsigned short _month : 4;
    Week _day : 4;
    unsigned short _holiday : 1;
};

struct DayStatusShort
{
    unsigned short _date : 4;
    unsigned short _month : 4;
    unsigned short _day : 4;
    unsigned short _holiday : 1;
};

struct Status
{
    unsigned char clear_to_send;
    unsigned char data_ready;
    unsigned char record_end;
    unsigned char received_line;
    unsigned char trans_allowed;
    unsigned char line_ready;
    unsigned char ring_detected;
    unsigned char signal_accepted;
};

struct StatusByte
{
    unsigned char clear_to_send : 1;
    unsigned char data_ready : 1;
    unsigned char record_end : 1;
    unsigned char received_line : 1;
    unsigned char trans_allowed : 1;
    unsigned char line_ready : 1;
    unsigned char ring_detected : 1;
    unsigned char signal_accepted : 1;
};

struct AnotherStatusByte
{
    unsigned char _data_ready : 1;
    unsigned char _record_end : 1;
    unsigned char _line_ready : 1;
    unsigned char _signal_accepted : 1;
};

struct HalfWord
{
    short unsigned int _operand : 12;
    short unsigned int _oper : 4;
};

// 5. Unions

union Word
{
    uint64_t _k;
    float _x;
    struct
    {
        unsigned _byte1 : 8;
        unsigned _byte2 : 8;
        unsigned _byte3 : 8;
        unsigned _byte4 : 8;
    } _word;
    char _w[4];
};

union DoubleWord
{
    int64_t _k;
    double _x;
    struct
    {
        Word _w1;
        Word _w2;
    } _word;
    char _w[8];
};
