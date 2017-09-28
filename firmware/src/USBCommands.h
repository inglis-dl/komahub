/*
 * Copyright (c) 2016 Jari Saukkonen
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef USBCOMMANDS_H
#define USBCOMMANDS_H

enum USBCommand {
    END = 0x00,
    IDENTIFY = 0x01,
    GETFACTORYSETTINGS = 0x02,
    GETOUTPUTSETTINGS = 0x03,
    GETSTATUS = 0x04,
    SETRELAY = 0x10,
    SETPWMDUTY = 0x11,
    RESETFUSE = 0x12,
    CONFIGUREOUTPUT = 0x13,

    DUMPFACTORY = 0xF0,
    DUMPOUTPUTS = 0xF1,
    DUMPSTATE = 0xF2,
    FACTORYRESET = 0xFA
};

struct FactoryResetCommand {
    uint16_t serial;
    uint16_t r6ohms;
    uint16_t r7ohms;
};

struct GetOutputSettingsCommand {
    uint8_t outputNumber;
};

struct UpdateSettingsCommand {
    uint8_t features;
    uint8_t sqmzeropoint;
    uint8_t fusespeed;
};

struct SetRelayCommand {
    uint8_t outputNumber;
    uint8_t enabled;
};

struct SetPwmDutyCommand {
    uint8_t outputNumber;
    uint8_t duty; // 0-100
};

struct ResetFuseCommand {
    uint8_t outputNumber;
};

struct ConfigureOutputCommand {
    uint8_t outputNumber;
    uint8_t outputType;  
    uint8_t fuseCurrent;
    char name[16];
};


#endif