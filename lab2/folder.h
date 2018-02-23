#ifndef FOLDER_H
#define FOLDER_H

#include "file.h"

const int FOLDER_DEFAULT_SIZE = 4;

class Folder
{
public:
	Folder(unsigned int size = FOLDER_DEFAULT_SIZE);
	~Folder();
	Folder(const Folder &folder);

	void addFile(const File &file);
	bool contains(const File &file) const;
	void print() const;

private:
	int maxSize;
	int currSize;
	const File **files;
};

#endif