#include "core/Application.h"

int main() 
{
  Freeze::Application *application = new Freeze::Application();
  FZ_INFO("Freeze Engine v0.3_DEV");

  application->OnInit(1280, 720, "Freeze Engine v0.3_DEV");
  application->Run();

  delete application;
}
