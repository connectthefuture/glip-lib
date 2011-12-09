// Includes
	#include <iostream>
	#include "GLIPLib.hpp"
	#include <QApplication>
	#include <QDesktopWidget>
	#include <QtCore/QTimer>

const char* testKey = " attribute const uniform varying layout centroid flat smooth noperspective patch sample break continue do for while switch case default if else subroutine in out inout float double int void bool true false invariant discard return mat2 mat3 mat4 dmat2 dmat3 dmat4 mat2x2 mat2x3 mat2x4 dmat2x2 dmat2x3 dmat2x4 mat3x2 mat3x3 mat3x4 dmat3x2 dmat3x3 dmat3x4 mat4x2 mat4x3 mat4x4 dmat4x2 dmat4x3 dmat4x4 vec2 vec3 vec4 ivec2 ivec3 ivec4 bvec2 bvec3 bvec4 dvec2 dvec3 dvec4 uint uvec2 uvec3 uvec4 lowp mediump highp precision sampler1D sampler2D sampler3D samplerCube sampler1DShadow sampler2DShadow samplerCubeShadow sampler1DArray sampler2DArray sampler1DArrayShadow sampler2DArrayShadow isampler1D isampler2D isampler3D isamplerCube isampler1DArray isampler2DArray usampler1D usampler2D usampler3D usamplerCube usampler1DArray usampler2DArray sampler2DRect sampler2DRectShadow isampler2DRect usampler2DRect samplerBuffer isamplerBuffer usamplerBuffer sampler2DMS isampler2DMS usampler2DMS sampler2DMSArray isampler2DMSArray usampler2DMSArray samplerCubeArray samplerCubeArrayShadow isamplerCubeArray usamplerCubeArray struct common partition active asm class union enum typedef template this packed goto inline noinline volatile public static extern external interface long short half fixed unsigned superp input output hvec2 hvec3 hvec4 fvec2 fvec3 fvec4 sampler3DRect filter image1D image2D image3D imageCube iimage1D iimage2D iimage3D iimageCube uimage1D uimage2D uimage3D uimageCube image1DArray image2DArray iimage1DArray iimage2DArray uimage1DArray uimage2DArray image1DShadow image2DShadow image1DArrayShadow image2DArrayShadow imageBuffer iimageBuffer uimageBuffer sizeof cast namespace using row_major cast blabla ;";

int main(int argc, char** argv)
{
    std::cout << "Test ShaderSource" << std::endl;

    QApplication app(argc, argv);

    try
    {
        std::string filename = "./Filters/local_max_horiz.glsl";
        std::fstream file;
        file.open(filename.c_str());
        Glip::CoreGL::ShaderSource shader(file, filename);
        //Glip::CoreGL::ShaderSource shader(testKey);
        std::cout << "There are : " << shader.getInputVars().size() <<  " Input variables" << std::endl;
        for(unsigned int i=0; i<shader.getInputVars().size(); i++)
            std::cout << "    -> " << shader.getInputVars()[i] << std::endl;
        std::cout << "There are : " << shader.getOutputVars().size() << " Output variables" << std::endl;
        for(unsigned int i=0; i<shader.getInputVars().size(); i++)
            std::cout << "    -> " << shader.getOutputVars()[i] << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Caught an exception : " << std::endl << e.what() << std::endl;
    }

    std::cout << "End Test ShaderSource" << std::endl;

    return 0;
}
