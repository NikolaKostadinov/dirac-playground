#pragma once

struct Color
{
    unsigned char red  ;
    unsigned char green;
    unsigned char blue ;

    Color(
        unsigned char _red_,
        unsigned char _green_,
        unsigned char _blue_
    )
    {
        red   = _red_  ;
        green = _green_;
        blue  = _blue_ ;
    }
};