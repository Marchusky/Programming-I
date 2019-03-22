#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

// TODO 1: Create the declaration of ModuleWindow class
class ModuleWindow: public Module
{
	bool Init()		 override;
	bool CleanUp()	 override;
};
#endif // __ModuleWindow_H__