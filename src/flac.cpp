#include "FLAC++/decoder.h"
#include "daisy_pod.h"

static FLAC__uint64 total_samples = 0;
static uint32_t channels = 0;
static uint32_t bps = 0;

class Decoder: public FLAC::Decoder::Stream {
public: Decoder(): FLAC::Decoder::Stream() { }
    daisy::AudioHandle::OutputBuffer *out;
public:
    void set_output(daisy::AudioHandle::OutputBuffer new_out) {
        out = &new_out;
    }
protected: 
    virtual ::FLAC__StreamDecoderWriteStatus write_callback(const ::FLAC__Frame *frame, const FLAC__int32 *const buffer[]);
    virtual ::FLAC__StreamDecoderReadStatus read_callback(FLAC__byte buffer[], size_t *bytes);
    virtual void error_callback(::FLAC__StreamDecoderErrorStatus status);
private:
	Decoder(const Decoder&);
	Decoder&operator=(const Decoder&);
};

::FLAC__StreamDecoderWriteStatus Decoder::write_callback(const ::FLAC__Frame *frame, const FLAC__int32 * const buffer[]) {
	size_t i;

    channels = Decoder::get_channels();
	bps = Decoder::get_bits_per_sample();


    if(total_samples == 0) {
		return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
	}
	if(channels != 2 || bps != 16) {
		return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
	}

    for(i = 0; i < frame->header.blocksize; i++) {
		*out[i][0] = (float)buffer[0][i];     /* left channel, a simple cast from int32 to float is probably not what we want here */
		*out[i][0] = (float)buffer[1][i];     /* right channel */
	}

    return FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE;
}


