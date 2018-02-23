#include <iostream>

#include "folder.h"

using namespace std;

Folder::Folder(unsigned int size): maxSize(size), currSize{0} {
    files = new const File* [currSize];
}

Folder::~Folder() {
    delete[] files;	
}

Folder::Folder(const Folder &folder): maxSize(folder.maxSize), currSize{folder.currSize} {
    files = new const File* [currSize];
    for (int i=0; i<currSize; i++) files[i] = new File{*folder.files[i]};
}

void Folder::addFile(const File &file) {
	if (this->contains(file)) {
        cout << "File already exists in folder" << endl;
        return;
    }
    if (currSize == maxSize) {
        cout << "Insufficient space for folder" << endl;
        return;
    }
    
    const File** temp = new const File* [currSize + 1];
    for (int i=0; i<currSize; i++) temp[i] = files[i];
    temp[currSize] = &file;
    currSize++;
    delete[] files;
    files = temp;
}

bool Folder::contains(const File &file) const {
    for (int i=0; i<currSize; i++) if (files[i]->equals(file)) return true;
	return false;
}

void Folder::print() const {
	for (int i=0; i<currSize; i++) files[i]->print();
}
