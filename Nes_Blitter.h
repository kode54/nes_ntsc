
// NTSC filter for use with Nes_Emu

#ifndef NES_BLITTER_H
#define NES_BLITTER_H

#include <nes_emu/Nes_Emu.h>
#include "nes_ntsc.h"
	
class Nes_Blitter {
public:
	Nes_Blitter();
	~Nes_Blitter();
	
	blargg_err_t init();
	
	struct setup_t
	{
		nes_ntsc_setup_t ntsc;
		struct {
			// Number of NES source pixels to remove from each border.
			// Resulting width will be rounded to multiple of 6 pixels due
			// to internal limitations.
			int left, top, right, bottom;
		} crop;
	};
	setup_t const& setup() const { return setup_; }
	blargg_err_t setup( setup_t const& );
	
	// size of output image generated by blit()
	inline int out_width() const  { return NES_NTSC_OUT_WIDTH( width ); }
	inline int rescale_width() const { return NES_NTSC_RESCALE_WIDTH( out_width() ); }
	inline int out_height() const { return height; }
	
	// Generate NTSC filtered image to 16-bit 565 RGB output pixels
	void blit( Nes_Emu&, void* out, long pitch );
	
private:
	setup_t setup_;
	nes_ntsc_t* ntsc;
	int width;
	int height;
};

#endif

