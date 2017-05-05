# Using OpenCV with Managed C++(CLR) and WinForm

## Build Environment
* Windows 10
* Visual Studio 2015
* OpenCV 2.4.9 (32bit)

## Project Settings
1. Create a new `CLR Empty Project`
2. Right click the project, navigate to `Add`-`new item`
3. Add a new `Visual C++`-`UI`-`Windows Form`. Then there sould be `MyForm.cpp` and `MyForm.h`
4. Copy & paste the following code in `MyForm.cpp`
```cpp
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
System::Void Main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew clr_test::MyForm());
}

```
5. Go to `Project property`
	1. Set `Linker`-`System`-`Subsystem` to `/SUBSYSTEM:WINDOWS`
    2. Set `Linker`-`Advanced`-`Entry Point` to `Main`
    3. Set the paths of header and lib files of OpenCV
6. Build and run. Enjoy the OpenCV with CLR!

## OpenCV `Mat` to .Net `Bitmap`
```cpp
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat img = imread("D:\\opencv-2.4.9\\Lenna.jpg");
	Bitmap^ bmp = gcnew System::Drawing::Bitmap(
		img.cols, img.rows, img.step,
		System::Drawing::Imaging::PixelFormat::Format24bppRgb,
		(System::IntPtr)img.ptr());

	pictureBox1->Image = bmp;
	pictureBox1->Refresh();
}
```