#include "pch.h"

using namespace MediaCaptureReader;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Windows::Media::Capture;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::UI::Core;

TEST_CLASS(MediaGraphicsDeviceTests)
{
public:

    /* Currently unable to run the test as MediaCapture tries to pop up a consent UI which is nowhere to be seen

    TEST_METHOD(CX_W_MGD_Basic)
    {
        Await(CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(
            CoreDispatcherPriority::Normal, 
            ref new DispatchedHandler([]()
        {
            auto capture = ref new MediaCapture();
            Await(capture->InitializeAsync());

            auto device = MediaGraphicsDevice::CreateFromMediaCapture(capture);
            Assert::IsNotNull(device);
        })));
    }

    */
};
