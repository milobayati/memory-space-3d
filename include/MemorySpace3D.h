#ifndef MEMORY_SPACE_3D_H
#define MEMORY_SPACE_3D_H

#include <vector>
#include <string>
#include <glm/glm.hpp>

// ساختار برای هر بلاک حافظه
struct MemoryBlock {
    glm::vec3 position;
    glm::vec3 color;
    float size;
    long long bytes;
    std::string label;
};

// کلاس برای مدیریت فضای حافظه ۳بعدی
class MemorySpace3D {
private:
    std::vector<MemoryBlock> blocks;
    float scaleFactor;
    long long totalMemory;
    long long usedMemory;
    
    // توابع کمکی
    void parseMemInfo();
    void createMemoryVisualization();
    glm::vec3 calculatePosition(int index, int total);
    glm::vec3 getColorByUsage(float usagePercent);
    
public:
    // سازنده
    MemorySpace3D(float scale = 10000.0f);
    
    // متوتی اصلی
    void readSystemMemory();
    void printMemoryMap();
    void exportToJSON(const std::string& filename);
    
    // گترهای داده
    const std::vector<MemoryBlock>& getBlocks() const;
    long long getTotalMemory() const;
    long long getUsedMemory() const;
    float getUsagePercent() const;
};

#endif // MEMORY_SPACE_3D_H
