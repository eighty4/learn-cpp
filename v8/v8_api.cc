#include <cstdio>
#include <string>

#include "v8/include/libplatform/libplatform.h"
#include "v8/include/v8-context.h"
#include "v8/include/v8-initialization.h"
#include "v8/include/v8-isolate.h"
#include "v8/include/v8-message.h"
#include "v8/include/v8-local-handle.h"
#include "v8/include/v8-primitive.h"
#include "v8/include/v8-script.h"

int main([[maybe_unused]] int argc, char *argv[]) {
    // Initialize V8.
    v8::V8::InitializeICUDefaultLocation(argv[0]);
    v8::V8::InitializeExternalStartupData(argv[0]);
    std::unique_ptr<v8::Platform> platform = v8::platform::NewDefaultPlatform();
    v8::V8::InitializePlatform(platform.get());
#ifdef V8_ENABLE_SANDBOX
    if (!v8::V8::InitializeSandbox()) {
    fprintf(stderr, "Error initializing the V8 sandbox\n");
    return 1;
  }
#endif
    v8::V8::Initialize();

    // Create a new Isolate and make it the current one.
    v8::Isolate::CreateParams create_params;
    create_params.array_buffer_allocator =
            v8::ArrayBuffer::Allocator::NewDefaultAllocator();
    v8::Isolate *isolate = v8::Isolate::New(create_params);
    {
        v8::Isolate::Scope isolate_scope(isolate);
        v8::HandleScope handle_scope(isolate);
        v8::Local<v8::Context> context = v8::Context::New(isolate);
        v8::Context::Scope context_scope(context);

        {
//            isolate->SetHostInitializeImportMetaObjectCallback();
            auto srcStr = "import 'foo'";
            v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate, srcStr).ToLocalChecked();
            v8::Local<v8::Script> script = v8::Script::Compile(context, source).ToLocalChecked();

            v8::ScriptOrigin(isolate,
                             v8::String::NewFromUtf8(isolate, "main.mjs").ToLocalChecked(),
                             0,
                             0,
                             false,
                             -1
            );

            v8::Local<v8::Value> result = script->Run(context).ToLocalChecked();
            v8::String::Utf8Value utf8(isolate, result);
            printf("%s\n", *utf8);
        }
    }

    isolate->Dispose();
    v8::V8::Dispose();
    v8::V8::DisposePlatform();
    delete create_params.array_buffer_allocator;
    return 0;
}
