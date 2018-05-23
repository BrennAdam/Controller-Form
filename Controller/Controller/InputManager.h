#pragma once
#define WIN32_LEAN_AND_MEAN 1


#include <Windows.h>
#include <Xinput.h>


using namespace System::Collections::Generic;

ref class InputManager
{
public:

	static InputManager^ GetInstance()
	{
		if (!instance)
		{
			instance = gcnew InputManager;
		}

		return instance;
	}

	~InputManager() {}

	void update()
	{
		XINPUT_STATE controllerState;
		ZeroMemory(&controllerState, sizeof(XINPUT_STATE));
		XInputGetState(0, &controllerState);
		
			
			Apressed = (controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_A);
			Bpressed = (controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_B);
			Xpressed = (controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_X);
			Ypressed = (controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_Y);

			Backpressed = (controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_BACK);
			Startpressed = (controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_START);

			upDpressed = (controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP);
			leftDpressed = (controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT);
			downDpressed = (controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN);
			rightDpressed = (controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT);

			Lbumperpressed = (controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER);
			Rbumperpressed = (controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER);

			LtriggerNormals = controllerState.Gamepad.bLeftTrigger / 255.0f;
			RtriggerNormals = controllerState.Gamepad.bRightTrigger / 255.0f;

			LanalogXNromalized = (float)controllerState.Gamepad.sThumbLX / 32767;
			LanalogYNromalized = (float)controllerState.Gamepad.sThumbLY / 32767;

			RanalogXNromalized = (float)controllerState.Gamepad.sThumbRX / 32767;
			RanalogYNromalized = (float)controllerState.Gamepad.sThumbRY / 32767;
	}


	property bool Apress
	{
		bool get()
		{
			return Apressed;
		}

		void set(bool val)
		{
			Apressed = val;
		}
	}

	property bool Bpress
	{
		bool get()
		{
			return Bpressed;
		}

		void set(bool val)
		{
			Bpressed = val;
		}
	}

	property bool Xpress
	{
		bool get()
		{
			return Xpressed;
		}

		void set(bool val)
		{
			Xpressed = val;
		}
	}

	property bool Ypress
	{
		bool get()
		{
			return Ypressed;
		}

		void set(bool val)
		{
			Ypressed = val;
		}
	}
	
	property bool Backpress
	{
		bool get()
		{
			return Backpressed;
		}

		void set(bool val)
		{
			Backpressed = val;
		}
	}

	property bool Startpress
	{
		bool get()
		{
			return Startpressed;
		}

		void set(bool val)
		{
			Startpressed = val;
		}
	}

	property bool UpDpress
	{
		bool get()
		{
			return upDpressed;
		}

		void set(bool val)
		{
			upDpressed = val;
		}
	}

	property bool LDpress
	{
		bool get()
		{
			return leftDpressed;
		}

		void set(bool val)
		{
			leftDpressed = val;
		}
	}

	property bool DownDpress
	{
		bool get()
		{
			return downDpressed;
		}

		void set(bool val)
		{
			downDpressed = val;
		}
	}

	property bool RDpress
	{
		bool get()
		{
			return rightDpressed;
		}

		void set(bool val)
		{
			rightDpressed = val;
		}
	}

	property bool Lbumperpress
	{
		bool get()
		{
			return Lbumperpressed;
		}

		void set(bool val)
		{
			Lbumperpressed = val;
		}
	}

	property bool Rbumperpress
	{
		bool get()
		{
			return Rbumperpressed;
		}

		void set(bool val)
		{
			Rbumperpressed = val;
		}
	}

	property float Ltriggerpress
	{
		float get()
		{
			return LtriggerNormals;
		}

		void set(float val)
		{
			LtriggerNormals = val;
		}
	}

	property float Rtriggerpress
	{
		float get()
		{
			return RtriggerNormals;
		}

		void set(float val)
		{
			RtriggerNormals = val;
		}
	}

	property float LanalogX
	{
		float get()
		{
			return LanalogXNromalized;
		}

		void set(float val)
		{
			LanalogXNromalized = val;
		}
	}

	property float LanalogY
	{
		float get()
		{
			return LanalogYNromalized;
		}

		void set(float val)
		{
			LanalogYNromalized = val;
		}
	}

	property float RanalogX
	{
		float get()
		{
			return RanalogXNromalized;
		}

		void set(float val)
		{
			RanalogXNromalized = val;
		}
	}

	property float RanalogY
	{
		float get()
		{
			return RanalogYNromalized;
		}

		void set(float val)
		{
			RanalogYNromalized = val;
		}
	}

private:

	static InputManager^ instance;

	bool Apressed;
	bool Bpressed;
	bool Xpressed; 
	bool Ypressed;

	bool Backpressed;
	bool Startpressed;

	bool upDpressed;
	bool leftDpressed;
	bool downDpressed;
	bool rightDpressed;

	bool Lbumperpressed;
	bool Rbumperpressed;

	float LtriggerNormals;
	float RtriggerNormals;

	float LanalogXNromalized;
	float LanalogYNromalized;

	float RanalogXNromalized;
	float RanalogYNromalized;

};