#include "filestreambuf.h"

FileStreamBuf::FileStreamBuf(FILE* fp) : fp(fp) {
	resetSuperOPtrs();
	// set in ptrs to tell the stream, that 
	//  everything from buf already read
	setg(buf, buf + len, buf + len);
}
FileStreamBuf::~FileStreamBuf() {
	delete[] buf;
	buf = nullptr;
	fclose(fp);
	fp = nullptr;
}

void FileStreamBuf::resetSuperOPtrs() {
	setp(buf, buf + len);
}

int FileStreamBuf::overflow(int c) {
	fwrite(buf, sizeof(char), len, fp);
	buf[0] = (char) c;
	setp(buf + 1, buf + len);
	return c;
}

int FileStreamBuf::underflow() {
	fread(buf, sizeof(char), len, fp);
	setg(buf, buf, buf + len);
	return buf[0];
}

int FileStreamBuf::uflow() {
	fread(buf, sizeof(char), len, fp);
	setg(buf, buf + 1, buf + len);
	return buf[0];
}

int FileStreamBuf::sync() {
	if (!fwrite(buf, sizeof(char), pptr()-buf, fp))
		return -1;
	resetSuperOPtrs();
	return 0;
}
