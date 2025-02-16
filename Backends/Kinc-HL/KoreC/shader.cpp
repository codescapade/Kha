#include <Kore/Graphics4/Graphics.h>
#include <Kore/Graphics4/PipelineState.h>
#include <hl.h>

Kore::Graphics4::ZCompareMode convertCompareMode(int mode) {
	switch (mode) {
	case 0:
		return Kore::Graphics4::ZCompareAlways;
	case 1:
		return Kore::Graphics4::ZCompareNever;
	case 2:
		return Kore::Graphics4::ZCompareEqual;
	case 3:
		return Kore::Graphics4::ZCompareNotEqual;
	case 4:
		return Kore::Graphics4::ZCompareLess;
	case 5:
		return Kore::Graphics4::ZCompareLessEqual;
	case 6:
		return Kore::Graphics4::ZCompareGreater;
	case 7:
	default:
		return Kore::Graphics4::ZCompareGreaterEqual;
	}
}

Kore::Graphics4::StencilAction convertStencilAction(int action) {
	switch (action) {
	case 0:
		return Kore::Graphics4::Keep;
	case 1:
		return Kore::Graphics4::Zero;
	case 2:
		return Kore::Graphics4::Replace;
	case 3:
		return Kore::Graphics4::Increment;
	case 4:
		return Kore::Graphics4::IncrementWrap;
	case 5:
		return Kore::Graphics4::Decrement;
	case 6:
		return Kore::Graphics4::DecrementWrap;
	case 7:
	default:
		return Kore::Graphics4::Invert;
	}
}

Kore::Graphics4::RenderTargetFormat convertColorAttachment(int format) {
	switch (format) {
	case 0:
		return Kore::Graphics4::Target32Bit;
	case 1:
		return Kore::Graphics4::Target8BitRed;
	case 2:
		return Kore::Graphics4::Target128BitFloat;
	case 3:
		return Kore::Graphics4::Target16BitDepth;
	case 4:
		return Kore::Graphics4::Target64BitFloat;
	case 5:
		return Kore::Graphics4::Target32BitRedFloat;
	case 6:
	default:
		return Kore::Graphics4::Target16BitRedFloat;
	}
}

extern "C" vbyte *hl_kore_create_vertexshader(vbyte *data, int length) {
	return (vbyte *)new Kore::Graphics4::Shader(data, length, Kore::Graphics4::VertexShader);
}

extern "C" vbyte *hl_kore_create_fragmentshader(vbyte *data, int length) {
	return (vbyte *)new Kore::Graphics4::Shader(data, length, Kore::Graphics4::FragmentShader);
}

extern "C" vbyte *hl_kore_create_geometryshader(vbyte *data, int length) {
	return (vbyte *)new Kore::Graphics4::Shader(data, length, Kore::Graphics4::GeometryShader);
}

extern "C" vbyte *hl_kore_create_tesscontrolshader(vbyte *data, int length) {
	return (vbyte *)new Kore::Graphics4::Shader(data, length, Kore::Graphics4::TessellationControlShader);
}

extern "C" vbyte *hl_kore_create_tessevalshader(vbyte *data, int length) {
	return (vbyte *)new Kore::Graphics4::Shader(data, length, Kore::Graphics4::TessellationEvaluationShader);
}

extern "C" vbyte *hl_kore_vertexshader_from_source(vbyte *source) {
	return (vbyte *)new Kore::Graphics4::Shader((char *)source, Kore::Graphics4::VertexShader);
}

extern "C" vbyte *hl_kore_fragmentshader_from_source(vbyte *source) {
	return (vbyte *)new Kore::Graphics4::Shader((char *)source, Kore::Graphics4::FragmentShader);
}

extern "C" vbyte *hl_kore_geometryshader_from_source(vbyte *source) {
	return (vbyte *)new Kore::Graphics4::Shader((char *)source, Kore::Graphics4::GeometryShader);
}

extern "C" vbyte *hl_kore_tesscontrolshader_from_source(vbyte *source) {
	return (vbyte *)new Kore::Graphics4::Shader((char *)source, Kore::Graphics4::TessellationControlShader);
}

extern "C" vbyte *hl_kore_tessevalshader_from_source(vbyte *source) {
	return (vbyte *)new Kore::Graphics4::Shader((char *)source, Kore::Graphics4::TessellationEvaluationShader);
}

extern "C" vbyte *hl_kore_create_pipeline() {
	return (vbyte *)new Kore::Graphics4::PipelineState();
}

extern "C" void hl_kore_delete_pipeline(vbyte *pipeline) {
	Kore::Graphics4::PipelineState *pipe = (Kore::Graphics4::PipelineState *)pipeline;
	delete pipe;
}

extern "C" void hl_kore_pipeline_set_vertex_shader(vbyte *pipeline, vbyte *shader) {
	Kore::Graphics4::PipelineState *pipe = (Kore::Graphics4::PipelineState *)pipeline;
	Kore::Graphics4::Shader *sh = (Kore::Graphics4::Shader *)shader;
	pipe->vertexShader = sh;
}

extern "C" void hl_kore_pipeline_set_fragment_shader(vbyte *pipeline, vbyte *shader) {
	Kore::Graphics4::PipelineState *pipe = (Kore::Graphics4::PipelineState *)pipeline;
	Kore::Graphics4::Shader *sh = (Kore::Graphics4::Shader *)shader;
	pipe->fragmentShader = sh;
}

extern "C" void hl_kore_pipeline_set_geometry_shader(vbyte *pipeline, vbyte *shader) {
	Kore::Graphics4::PipelineState *pipe = (Kore::Graphics4::PipelineState *)pipeline;
	Kore::Graphics4::Shader *sh = (Kore::Graphics4::Shader *)shader;
	pipe->geometryShader = sh;
}

extern "C" void hl_kore_pipeline_set_tesscontrol_shader(vbyte *pipeline, vbyte *shader) {
	Kore::Graphics4::PipelineState *pipe = (Kore::Graphics4::PipelineState *)pipeline;
	Kore::Graphics4::Shader *sh = (Kore::Graphics4::Shader *)shader;
	pipe->tessellationControlShader = sh;
}

extern "C" void hl_kore_pipeline_set_tesseval_shader(vbyte *pipeline, vbyte *shader) {
	Kore::Graphics4::PipelineState *pipe = (Kore::Graphics4::PipelineState *)pipeline;
	Kore::Graphics4::Shader *sh = (Kore::Graphics4::Shader *)shader;
	pipe->tessellationEvaluationShader = sh;
}

extern "C" void hl_kore_pipeline_compile(vbyte *pipeline, vbyte *structure0, vbyte *structure1, vbyte *structure2, vbyte *structure3) {
	Kore::Graphics4::PipelineState *pipe = (Kore::Graphics4::PipelineState *)pipeline;
	pipe->inputLayout[0] = (Kore::Graphics4::VertexStructure *)structure0;
	pipe->inputLayout[1] = (Kore::Graphics4::VertexStructure *)structure1;
	pipe->inputLayout[2] = (Kore::Graphics4::VertexStructure *)structure2;
	pipe->inputLayout[3] = (Kore::Graphics4::VertexStructure *)structure3;
	pipe->inputLayout[4] = nullptr;
	pipe->compile();
}

extern "C" void hl_kore_pipeline_set_states(vbyte *pipeline, int cullMode, int depthMode, int stencilFrontMode, int stencilFrontBothPass,
                                            int stencilFrontDepthFail, int stencilFrontFail, int stencilBackMode, int stencilBackBothPass,
                                            int stencilBackDepthFail, int stencilBackFail, int blendSource, int blendDestination, int alphaBlendSource,
                                            int alphaBlendDestination, bool depthWrite, int stencilReferenceValue, int stencilReadMask, int stencilWriteMask,
                                            bool colorWriteMaskRed, bool colorWriteMaskGreen, bool colorWriteMaskBlue, bool colorWriteMaskAlpha,
                                            int colorAttachmentCount, int colorAttachment0, int colorAttachment1, int colorAttachment2, int colorAttachment3,
                                            int colorAttachment4, int colorAttachment5, int colorAttachment6, int colorAttachment7, int depthAttachmentBits,
                                            int stencilAttachmentBits, bool conservativeRasterization) {

	Kore::Graphics4::PipelineState *pipe = (Kore::Graphics4::PipelineState *)pipeline;

	switch (cullMode) {
	case 0:
		pipe->cullMode = Kore::Graphics4::Clockwise;
		break;
	case 1:
		pipe->cullMode = Kore::Graphics4::CounterClockwise;
		break;
	case 2:
		pipe->cullMode = Kore::Graphics4::NoCulling;
		break;
	}

	switch (depthMode) {
	case 0:
		pipe->depthMode = Kore::Graphics4::ZCompareAlways;
		break;
	case 1:
		pipe->depthMode = Kore::Graphics4::ZCompareNever;
		break;
	case 2:
		pipe->depthMode = Kore::Graphics4::ZCompareEqual;
		break;
	case 3:
		pipe->depthMode = Kore::Graphics4::ZCompareNotEqual;
		break;
	case 4:
		pipe->depthMode = Kore::Graphics4::ZCompareLess;
		break;
	case 5:
		pipe->depthMode = Kore::Graphics4::ZCompareLessEqual;
		break;
	case 6:
		pipe->depthMode = Kore::Graphics4::ZCompareGreater;
		break;
	case 7:
		pipe->depthMode = Kore::Graphics4::ZCompareGreaterEqual;
		break;
	}
	pipe->depthWrite = depthWrite;

	pipe->stencilFrontMode = convertCompareMode(stencilFrontMode);
	pipe->stencilFrontBothPass = convertStencilAction(stencilFrontBothPass);
	pipe->stencilFrontDepthFail = convertStencilAction(stencilFrontDepthFail);
	pipe->stencilFrontFail = convertStencilAction(stencilFrontFail);

	pipe->stencilBackMode = convertCompareMode(stencilBackMode);
	pipe->stencilBackBothPass = convertStencilAction(stencilBackBothPass);
	pipe->stencilBackDepthFail = convertStencilAction(stencilBackDepthFail);
	pipe->stencilBackFail = convertStencilAction(stencilBackFail);

	pipe->stencilReferenceValue = stencilReferenceValue;
	pipe->stencilReadMask = stencilReadMask;
	pipe->stencilWriteMask = stencilWriteMask;

	pipe->blendSource = (Kore::Graphics4::BlendingFactor)blendSource;
	pipe->blendDestination = (Kore::Graphics4::BlendingFactor)blendDestination;
	pipe->alphaBlendSource = (Kore::Graphics4::BlendingFactor)alphaBlendSource;
	pipe->alphaBlendDestination = (Kore::Graphics4::BlendingFactor)alphaBlendDestination;

	pipe->colorWriteMaskRed[0] = colorWriteMaskRed;
	pipe->colorWriteMaskGreen[0] = colorWriteMaskGreen;
	pipe->colorWriteMaskBlue[0] = colorWriteMaskBlue;
	pipe->colorWriteMaskAlpha[0] = colorWriteMaskAlpha;

	pipe->colorAttachmentCount = colorAttachmentCount;
	pipe->colorAttachment[0] = convertColorAttachment(colorAttachment0);
	pipe->colorAttachment[1] = convertColorAttachment(colorAttachment1);
	pipe->colorAttachment[2] = convertColorAttachment(colorAttachment2);
	pipe->colorAttachment[3] = convertColorAttachment(colorAttachment3);
	pipe->colorAttachment[4] = convertColorAttachment(colorAttachment4);
	pipe->colorAttachment[5] = convertColorAttachment(colorAttachment5);
	pipe->colorAttachment[6] = convertColorAttachment(colorAttachment6);
	pipe->colorAttachment[7] = convertColorAttachment(colorAttachment7);

	pipe->depthAttachmentBits = depthAttachmentBits;
	pipe->stencilAttachmentBits = stencilAttachmentBits;

	pipe->conservativeRasterization = conservativeRasterization;
}

extern "C" void hl_kore_pipeline_set(vbyte *pipeline) {
	Kore::Graphics4::PipelineState *pipe = (Kore::Graphics4::PipelineState *)pipeline;
	Kore::Graphics4::setPipeline(pipe);
}

extern "C" vbyte *hl_kore_pipeline_get_constantlocation(vbyte *pipeline, vbyte *name) {
	Kore::Graphics4::PipelineState *pipe = (Kore::Graphics4::PipelineState *)pipeline;
	return (vbyte *)new Kore::Graphics4::ConstantLocation(pipe->getConstantLocation((char *)name));
}

extern "C" vbyte *hl_kore_pipeline_get_textureunit(vbyte *pipeline, vbyte *name) {
	Kore::Graphics4::PipelineState *pipe = (Kore::Graphics4::PipelineState *)pipeline;
	return (vbyte *)new Kore::Graphics4::TextureUnit(pipe->getTextureUnit((char *)name));
}
