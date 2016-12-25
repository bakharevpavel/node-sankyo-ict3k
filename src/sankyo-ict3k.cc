#include "functions.h"

using v8::FunctionTemplate;

NAN_MODULE_INIT(InitAll) {
	Nan::Set(target, Nan::New("connect").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(connect)).ToLocalChecked());
	Nan::Set(target, Nan::New("exec").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(exec)).ToLocalChecked());
	Nan::Set(target, Nan::New("disconnect").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(disconnect)).ToLocalChecked());
}

NODE_MODULE(SankyoICT3K, InitAll)