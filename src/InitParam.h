#pragma once

typedef unsigned char byte;

#pragma pack(push, 1)
struct InitParam
{
	//0x00
	void* sv;
	unsigned reserved;

	//0x08
	struct Status {
		byte ended;
		byte playing;
		byte mute;
		byte showing;

		byte reserved_status[4];
	} status;

	//0x10
	struct Order {
		byte disableDududu;
		byte disableDialogSE;
		byte skipVoice;
		byte autoPlay;

		byte reserved_order[4];
	} order;

	//0x18
	void** p_ov_open_callbacks;
	//0x1C
	void** p_ov_info;
	//0x20
	void** p_ov_read;
	//0x24
	void** p_ov_clear;
	//0x28
	void** reserved_api[2];

	//0x30
	void** reserved_ptr[4];
	//0x40
	void** p_d3dd;
	//0x44
	void* p_Hwnd;
	//0x48
	void** p_pDS;
	//0x4C
	char* p_Keys;

	//0x50
	char keysOld[8];
};
#pragma pack(pop)



