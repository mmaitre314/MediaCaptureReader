#include "pch.h"

using namespace MediaCaptureReader;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::Storage;
using namespace Windows::Foundation;
using namespace Windows::Media::MediaProperties;
using namespace Windows::Graphics::Imaging;
using namespace Platform;
using namespace Microsoft::WRL;

TEST_CLASS(MediaReaderTests)
{
public:
    TEST_METHOD(CX_W_MediaReader_TestBasics)
    {
        auto reader = Await(MediaReader::CreateFromPathAsync(L"ms-appx:///car.mp4"));

        // Test MediaReader state
        Assert::IsTrue(reader->CanSeek);
        Assert::AreEqual(31578911i64, reader->Duration.Duration);
        Assert::AreEqual(1u, reader->VideoStreams->Size);
        Assert::AreEqual(1u, reader->AudioStreams->Size);
        Assert::AreEqual(0u, reader->OtherStreams->Size);

        //// TODO
        //// Test access to native IMFSourceReader
        //ComPtr<IMFSourceReaderEx> sourceReader;
        //CHK(GetNativeService<IMediaReaderNative>(reader)->GetSourceReader(&sourceReader));
        //Assert::IsNotNull(sourceReader.Get());

        // Read the first video frame
        Log() << "Reading sample";
        auto result = Await(reader->VideoStreams->GetAt(0)->ReadAsync());

        // Save it as JPEG
        Log() << "Saving sample";
        auto folder = Await(KnownFolders::PicturesLibrary->CreateFolderAsync(L"MediaCaptureReaderTests", CreationCollisionOption::OpenIfExists));
        auto file = Await(folder->CreateFileAsync(L"CX_W_MediaReader_TestBasics.jpg", CreationCollisionOption::ReplaceExisting));
        Await(MediaSampleEncoder::SaveToFileAsync(result->Sample, file, ContainerFormat::Jpeg));
        Log() << L"Saved " << file->Path->Data();
    }
};
