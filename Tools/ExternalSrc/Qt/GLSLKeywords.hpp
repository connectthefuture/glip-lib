/* ************************************************************************************************************* */
/*                                                                                                               */
/*     GLIP-LIB                                                                                                  */
/*     OpenGL Image Processing LIBrary                                                                           */
/*                                                                                                               */
/*     Author        : R. KERVICHE 			                                                         */
/*     LICENSE       : MIT License                                                                               */
/*     Website       : http://sourceforge.net/projects/glip-lib/                                                 */
/*                                                                                                               */
/*     File          : GLSLKeywords.hpp                                                                          */
/*     Original Date : July 6th 2014                                                                             */
/*                                                                                                               */
/*     Description   : GLSL Language keywords.                                                                   */
/*                                                                                                               */
/* ************************************************************************************************************* */

#ifndef __GLIPLIB_KEYWORDS__
#define __GLIPLIB_KEYWORDS__

namespace GLSLLanguage
{
	enum Keyword
	{
		KW_attribute,
		KW_const,
		KW_uniform,
		KW_varying,
		KW_layout,
		KW_centroid,
		KW_flat,
		KW_smooth,
		KW_noperspective,
		KW_patch,
		KW_sample,
		KW_break,
		KW_continue,
		KW_do,
		KW_for,
		KW_while,
		KW_switch,
		KW_case,
		KW_default,
		KW_if,
		KW_else,
		KW_subroutine,
		KW_in,
		KW_out,
		KW_inout,
		KW_float,
		KW_double,
		KW_int,
		KW_void,
		KW_bool,
		KW_true,
		KW_false,
		KW_invariant,
		KW_discard,
		KW_return,
		KW_mat2,
		KW_mat3,
		KW_mat4,
		KW_dmat2,
		KW_dmat3,
		KW_dmat4,
		KW_mat2x2,
		KW_mat2x3,
		KW_mat2x4,
		KW_dmat2x2,
		KW_dmat2x3,
		KW_dmat2x4,
		KW_mat3x2,
		KW_mat3x3,
		KW_mat3x4,
		KW_dmat3x2,
		KW_dmat3x3,
		KW_dmat3x4,
		KW_mat4x2,
		KW_mat4x3,
		KW_mat4x4,
		KW_dmat4x2,
		KW_dmat4x3,
		KW_dmat4x4,
		KW_vec2,
		KW_vec3,
		KW_vec4,
		KW_ivec2,
		KW_ivec3,
		KW_ivec4,
		KW_bvec2,
		KW_bvec3,
		KW_bvec4,
		KW_dvec2,
		KW_dvec3,
		KW_dvec4,
		KW_uint,
		KW_uvec2,
		KW_uvec3,
		KW_uvec4,
		KW_lowp,
		KW_mediump,
		KW_highp,
		KW_precision,
		KW_sampler1D,
		KW_sampler2D,
		KW_sampler3D,
		KW_samplerCube,
		KW_sampler1DShadow,
		KW_sampler2DShadow,
		KW_samplerCubeShadow,
		KW_sampler1DArray,
		KW_sampler2DArray,
		KW_sampler1DArrayShadow,
		KW_sampler2DArrayShadow,
		KW_isampler1D,
		KW_isampler2D,
		KW_isampler3D,
		KW_isamplerCube,
		KW_isampler1DArray,
		KW_isampler2DArray,
		KW_usampler1D,
		KW_usampler2D,
		KW_usampler3D,
		KW_usamplerCube,
		KW_usampler1DArray,
		KW_usampler2DArray,
		KW_sampler2DRect,
		KW_sampler2DRectShadow,
		KW_isampler2DRect,
		KW_usampler2DRect,
		KW_samplerBuffer,
		KW_isamplerBuffer,
		KW_usamplerBuffer,
		KW_sampler2DMS,
		KW_isampler2DMS,
		KW_usampler2DMS,
		KW_sampler2DMSArray,
		KW_isampler2DMSArray,
		KW_usampler2DMSArray,
		KW_samplerCubeArray,
		KW_samplerCubeArrayShadow,
		KW_isamplerCubeArray,
		KW_usamplerCubeArray,
		KW_struct,
		KW_common,
		KW_partition,
		KW_active,
		KW_asm,
		KW_class,
		KW_union,
		KW_enum,
		KW_typedef,
		KW_template,
		KW_this,
		KW_packed,
		KW_vgoto,
		KW_inline,
		KW_noinline,
		KW_volatile,
		KW_public,
		KW_static,
		KW_extern,
		KW_external,
		KW_interface,
		KW_long,
		KW_short,
		KW_half,
		KW_fixed,
		KW_unsigned,
		KW_superp,
		KW_input,
		KW_output,
		KW_hvec2,
		KW_hvec3,
		KW_hvec4,
		KW_fvec2,
		KW_fvec3,
		KW_fvec4,
		KW_sampler3DRect,
		KW_filter,
		KW_image1D,
		KW_image2D,
		KW_image3D,
		KW_imageCube,
		KW_iimage1D,
		KW_iimage2D,
		KW_iimage3D,
		KW_iimageCube,
		KW_uimage1D,
		KW_uimage2D,
		KW_uimage3D,
		KW_uimageCube,
		KW_image1DArray,
		KW_image2DArray,
		KW_iimage1DArray,
		KW_iimage2DArray,
		KW_uimage1DArray,
		KW_uimage2DArray,
		KW_image1DShadow,
		KW_image2DShadow,
		KW_image1DArrayShadow,
		KW_image2DArrayShadow,
		KW_imageBuffer,
		KW_iimageBuffer,
		KW_uimageBuffer,
		KW_sizeof,
		KW_cast,
		KW_namespace,
		KW_using,
		KW_row_major, // 185 lines
		KW_END
	};

	extern const char* GLSLKeywords[];

	enum Function
	{
		FN_abs,
		FN_acos,
		FN_acosh,
		FN_all,
		FN_any,
		FN_asin,
		FN_asinh,
		FN_atan,
		FN_atanh,
		FN_atomicAdd,
		FN_atomicAnd,
		FN_atomicCompSwap,
		FN_atomicCounter,
		FN_atomicCounterDecrement,
		FN_atomicCounterIncrement,
		FN_atomicExchange,
		FN_atomicMax,
		FN_atomicMin,
		FN_atomicOr,
		FN_atomicXor,
		FN_barrier,
		FN_bitCount,
		FN_bitfieldExtract,
		FN_bitfieldInsert,
		FN_bitfieldReverse,
		FN_ceil,
		FN_clamp,
		FN_cos,
		FN_cosh,
		FN_cross,
		FN_degrees,
		FN_determinant,
		FN_dFdx,
		FN_dFdy,
		FN_distance,
		FN_dot,
		FN_EmitStreamVertex,
		FN_EmitVertex,
		FN_EndPrimitive,
		FN_EndStreamPrimitive,
		FN_equal,
		FN_exp,
		FN_exp2,
		FN_faceforward,
		FN_findLSB,
		FN_findMSB,
		FN_floatBitsToInt,
		FN_floatBitsToUint,
		FN_floor,
		FN_fma,
		FN_fract,
		FN_frexp,
		FN_fwidth,
		FN_greaterThan,
		FN_greaterThanEqual,
		FN_groupMemoryBarrier,
		FN_imageAtomicAdd,
		FN_imageAtomicAnd,
		FN_imageAtomicCompSwap,
		FN_imageAtomicExchange,
		FN_imageAtomicMax,
		FN_imageAtomicMin,
		FN_imageAtomicOr,
		FN_imageAtomicXor,
		FN_imageLoad,
		FN_imageSize,
		FN_imageStore,
		FN_imulExtended,
		FN_intBitsToFloat,
		FN_interpolateAtCentroid,
		FN_interpolateAtOffset,
		FN_interpolateAtSample,
		FN_inverse,
		FN_inversesqrt,
		FN_isinf,
		FN_isnan,
		FN_ldexp,
		FN_length,
		FN_lessThan,
		FN_lessThanEqual,
		FN_log,
		FN_log2,
		FN_matrixCompMult,
		FN_max,
		FN_memoryBarrier,
		FN_memoryBarrierAtomicCounter,
		FN_memoryBarrierBuffer,
		FN_memoryBarrierImage,
		FN_memoryBarrierShared,
		FN_min,
		FN_mix,
		FN_mod,
		FN_modf,
		FN_noise,
		FN_normalize,
		FN_not,
		FN_notEqual,
		FN_outerProduct,
		FN_packDouble2x32,
		FN_packHalf2x16,
		FN_packSnorm2x16,
		FN_packSnorm4x8,
		FN_packUnorm2x16,
		FN_packUnorm4x8,
		FN_pow,
		FN_radians,
		FN_reflect,
		FN_refract,
		FN_round,
		FN_roundEven,
		FN_sign,
		FN_sin,
		FN_sinh,
		FN_smoothstep,
		FN_sqrt,
		FN_step,
		FN_tan,
		FN_tanh,
		FN_texelFetch,
		FN_texelFetchOffset,
		FN_texture,
		FN_textureGather,
		FN_textureGatherOffset,
		FN_textureGatherOffsets,
		FN_textureGrad,
		FN_textureGradOffset,
		FN_textureLod,
		FN_textureLodOffset,
		FN_textureOffset,
		FN_textureProj,
		FN_textureProjGrad,
		FN_textureProjGradOffset,
		FN_textureProjLod,
		FN_textureProjLodOffset,
		FN_textureProjOffset,
		FN_textureQueryLevels,
		FN_textureQueryLod,
		FN_textureSize,
		FN_transpose,
		FN_trunc,
		FN_uaddCarry,
		FN_uintBitsToFloat,
		FN_umulExtended,
		FN_unpackDouble2x32,
		FN_unpackHalf2x16,
		FN_unpackSnorm2x16,
		FN_unpackSnorm4x8,
		FN_unpackUnorm2x16,
		FN_unpackUnorm4x8,
		FN_usubBorrow,
		FN_gl_ClipDistance,
		FN_gl_FragCoord,
		FN_gl_FragDepth,
		FN_gl_FrontFacing,
		FN_gl_GlobalInvocationID,
		FN_gl_InstanceID,
		FN_gl_InvocationID,
		FN_gl_Layer,
		FN_gl_LocalInvocationID,
		FN_gl_LocalInvocationIndex,
		FN_gl_NumSamples,
		FN_gl_NumWorkGroups,
		FN_gl_PatchVerticesIn,
		FN_gl_PointCoord,
		FN_gl_PointSize,
		FN_gl_Position,
		FN_gl_PrimitiveID,
		FN_gl_PrimitiveIDIn,
		FN_gl_SampleID,
		FN_gl_SampleMask,
		FN_gl_SampleMaskIn,
		FN_gl_SamplePosition,
		FN_gl_TessCoord,
		FN_gl_TessLevelInner,
		FN_gl_TessLevelOuter,
		FN_gl_VertexID,
		FN_gl_ViewportIndex,
		FN_gl_WorkGroupID,
		FN_gl_WorkGroupSize,
		FN_END
	};

	extern const char* GLSLFunctions[];
}

#endif 
