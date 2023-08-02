#include "daisy_pod.h"
#include "flac.cpp"

using namespace daisy;

DaisyPod hardware;
Decoder decoder;

void AudioCallback(AudioHandle::InputBuffer  in,
                   AudioHandle::OutputBuffer out,
                   size_t                    size)
{
    decoder.set_output(out);
    decoder.process_single();
}

int main(void)
{
    decoder.init();
    hardware.Init();
    hardware.SetAudioBlockSize(4);

    hardware.StartAudio(AudioCallback);

    for(;;) {}
}