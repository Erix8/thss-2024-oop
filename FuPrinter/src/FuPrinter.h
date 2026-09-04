#pragma once

// FuPrinter is a console solution to an open-ended OOP assignment: "print a
// nice picture out of strings." Our chosen picture is the lucky character
// "福" (fú), drawn with whatever symbol the caller provides.
class FuPrinter
{
public:
    FuPrinter(char symbol = '&');

    void drawFu();

    char symbol_;   // which character to draw with
};
