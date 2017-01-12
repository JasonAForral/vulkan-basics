#include "Renderer.h"

#include <cstdlib>
#include <assert.h>

Renderer::Renderer()
{
	_InitInstance();
}


Renderer::~Renderer()
{
	_DeInitDevice();
}

void Renderer::_InitInstance()
{
	VkApplicationInfo application_info{};
	application_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	application_info.apiVersion = VK_API_VERSION_1_0;
	application_info.applicationVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo instance_create_info {};
	instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instance_create_info.pApplicationInfo = &application_info;

	auto err = vkCreateInstance(&instance_create_info, nullptr, &_instance);
	if (VK_SUCCESS != err) {
		assert(1 && "Vulkan ERROR: Create instance failed.");
		std::exit(-1);
	}
}

void Renderer::_DeInitInstance()
{
	vkDestroyInstance(_instance, nullptr);
	_instance = nullptr;
}
