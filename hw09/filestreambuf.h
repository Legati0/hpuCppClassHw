#ifndef FILESTREAMBUF_H
#define FILESTREAMBUF_H

#include <iostream>

class FileStreamBuf : public std::streambuf {
private:
	FILE* fp;
	int len = 4;
	char* buf = new char[len];

public:
	FileStreamBuf(FILE* fp);
	virtual ~FileStreamBuf();
	FileStreamBuf(const FileStreamBuf&) = delete;
	FileStreamBuf& operator=(const FileStreamBuf&) = delete;
	FileStreamBuf(const FileStreamBuf&&) = delete;
	FileStreamBuf& operator=(const FileStreamBuf&&) = delete;
	
	void resetSuperOPtrs();

	virtual int overflow(int c);
	virtual int underflow();
	virtual int uflow();
	virtual int sync();
};

#endif