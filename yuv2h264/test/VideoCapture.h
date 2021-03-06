#ifndef __VIDEOCAPTURE_H__
#define __VIDEOCAPTURE_H__

#include <linux/videodev2.h>
#include <string>

#include "X264Encoder.h"



struct Buffer {
	void 	*start;
	size_t 	length;
};

class CVideoCapture
{
public:
	CVideoCapture();
	~CVideoCapture();

	bool Start();
	bool Stop();
	void EventHandleLoop();

private:
	int Open(std::string devname, int width, int height);
	void InitMmap();
	void Close();

private:
	int						m_vfd;
	int 					m_buff_num;
	struct Buffer 			*m_buffers;

	struct v4l2_capability 	m_v4l2_cap;
	struct v4l2_cropcap 	m_v4l2_cropcap;
	struct v4l2_format 		m_v4l2_fmt;
	struct v4l2_crop 		m_v4l2_crop;

	CX264Encoder			m_x264encoder;
};

#endif


