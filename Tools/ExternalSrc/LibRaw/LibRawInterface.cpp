/* ************************************************************************************************************* */
/*                                                                                                               */
/*     LIBRAW INTERFACE                                                                                          */
/*     Interface to the LibRaw library for the OpenGL Image Processing LIBrary                                   */
/*                                                                                                               */
/*     Author        : R. KERVICHE (ronan.kerviche@free.fr)                                                      */
/*     LICENSE       : MIT License                                                                               */
/*     Website       : http://sourceforge.net/projects/glip-lib/                                                 */
/*                                                                                                               */
/*     File          : LibRawInterface.cpp                                                                       */
/*     Original Date : August 18th 2014                                                                          */
/*                                                                                                               */
/*     Description   : LibRaw interface for image input/output.                                                  */
/*                                                                                                               */
/* ************************************************************************************************************* */

// Includes :
	#include "LibRawInterface.hpp"

// Tools :
	Glip::Modules::ImageBuffer* libRawLoadImage(const std::string& filename)
	{
		int returnCode = 0;
		LibRaw rawProcessor;

		returnCode = rawProcessor.open_file(filename.c_str());
		if(returnCode!=LIBRAW_SUCCESS)
			throw Glip::Exception("libRawLoadImage - Error while loading the file " + filename + " : " + std::string(libraw_strerror(returnCode)) + ".", __FILE__, __LINE__);
	
		returnCode = rawProcessor.unpack();
		if(returnCode!=LIBRAW_SUCCESS)
			throw Glip::Exception("libRawLoadImage - Error while unpacking the file " + filename + " : " + std::string(libraw_strerror(returnCode)) + ".", __FILE__, __LINE__);
	
		libraw_decoder_info_t decoderInfo;
		rawProcessor.get_decoder_info(&decoderInfo);
		if(!(decoderInfo.decoder_flags & LIBRAW_DECODER_FLATFIELD))
			throw Glip::Exception("libRawLoadImage - Error while unpacking the file " + filename + " : not a Bayer-pattern RAW file.", __FILE__, __LINE__);

		Glip::CoreGL::HdlTextureFormat format(rawProcessor.imgdata.sizes.raw_width, rawProcessor.imgdata.sizes.raw_height, GL_LUMINANCE, GL_UNSIGNED_SHORT);
		Glip::Modules::ImageBuffer* imageBuffer = new Glip::Modules::ImageBuffer(format);

		std::memcpy(imageBuffer->getPtr(), rawProcessor.imgdata.rawdata.raw_image, format.getSize());
		
		return imageBuffer;
	}

