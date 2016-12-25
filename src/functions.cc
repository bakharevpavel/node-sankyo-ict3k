#include "functions.h";
#include "ICT3K5_6240DLL.h";
#include <atlbase.h>
#include <windows.h>

char *port = "";
DWORD baudRate;

using namespace v8;

NAN_METHOD(connect) {
    DWORD dwResult = 1;
    Local<Object> obj = info[0].As<Object>();
    Local<String> portFromObj = Nan::Get(info[0].As<Object>(), Nan::New("port").ToLocalChecked()).ToLocalChecked()->ToString();
    Nan::Utf8String val1(portFromObj);
    
    port = *val1;
    baudRate = Nan::Get(info[0].As<Object>(), Nan::New("baudRate").ToLocalChecked()).ToLocalChecked()->NumberValue();
    dwResult = ConnectDevice(port, (DWORD)baudRate);

    if(info[1]->IsFunction() == true) {
        const int argc = 1;
        Local<Value> argv[argc] = {Nan::New((int)dwResult)};
        Local<Function> callbackHandle = info[1].As<Function>();
        Nan::MakeCallback(Nan::GetCurrentContext()->Global(), callbackHandle, argc, argv);
    }
}

NAN_METHOD(exec) {
    COMMAND Command;
    REPLY Reply;
    DWORD dwResult = 1;
    Local<Object> obj = info[0].As<Object>();
    BYTE command = Nan::Get(obj, Nan::New("command").ToLocalChecked()).ToLocalChecked()->NumberValue();
    BYTE parameter = Nan::Get(obj, Nan::New("parameter").ToLocalChecked()).ToLocalChecked()->NumberValue();
    Local<Array> data = Nan::Get(obj, Nan::New("data").ToLocalChecked()).ToLocalChecked().As<Array>();
    int length = data->Length();

    Command.bCommandCode = command;
    Command.bParameterCode = parameter;
    
    if(length > 0) {
        BYTE *t = new BYTE[length];
        for(int i = 0; i < length; i++) {
            t[i] = (BYTE)data->Get(i)->NumberValue();
        }

        Command.Data.dwSize = length;
        Command.Data.lpbBody = t;
    } else {
        Command.Data.dwSize = 0;
    }

    dwResult = ExecuteCommand(port, Command, 2000, &Reply);

    if(info[1]->IsFunction() == true) {
        const int argc = 1;
        Local<Value> argv[argc] = {Nan::New((int)dwResult)};
        Local<Function> callbackHandle = info[1].As<Function>();
        Nan::MakeCallback(Nan::GetCurrentContext()->Global(), callbackHandle, argc, argv);
    }
}

NAN_METHOD(disconnect) {
    DWORD dwResult = DisconnectDevice(port);
    port = "";
    info.GetReturnValue().Set(1.75);
}