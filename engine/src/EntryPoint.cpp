#include "include/core/Application.h"

int main() {
  Freeze::Application *application = new Freeze::Application();
  FZ_INFO("Freeze Engine v0.1_DEV");

  application->OnInit(800, 600, "EntryPoint Application");
  application->Run();

  delete application;
}