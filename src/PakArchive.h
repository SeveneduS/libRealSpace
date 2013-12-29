//
//  PakArchive.h
//  libRealSpace
//
//  Created by fabien sanglard on 12/29/2013.
//  Copyright (c) 2013 Fabien Sanglard. All rights reserved.
//

#ifndef __libRealSpace__PakArchive__
#define __libRealSpace__PakArchive__

typedef struct PakEntry{
    
    uint8_t* data;
    size_t size;
    
} PakEntry;

class PakArchive{
    
    
    
public:
    PakArchive();
    ~PakArchive();
    
    bool InitFromFile(const char* filepath);
    void InitFromRAM(uint8_t* data, size_t size);
    

    bool Decompress(const char* dstDirectory);
    
    size_t GetNumEntries(void);
    PakEntry* GetEntry(size_t index);
    
    void List(FILE* output);
    
    void GuessContent(FILE* output);
    
private:

    ByteStream stream;
    
    void Parse(void);
    uint8_t* data;
    size_t size;
    char path[512] ;
    std::vector<PakEntry*> entries;
    
    // allows to know if we should free the TRE data
    bool initalizedFromFile ;
};

#endif /* defined(__libRealSpace__PakArchive__) */