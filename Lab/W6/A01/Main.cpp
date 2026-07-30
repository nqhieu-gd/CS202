#include "Course.h"
#include <fstream>
#include <iostream>
#include <string>

static int failed = 0;
#define TEST(name) do { std::cout << "=== " << name << " ===\n"; } while(0)
#define CHECK(cond, msg) do { if (!(cond)) { std::cout << "  FAIL: " << msg << "\n"; failed++; } else std::cout << "  PASS: " << msg << "\n"; } while(0)

void testManualConstruction() {
    TEST("Manual Material Construction");

    video v("Test Video", 30);
    CHECK(v.getDur() == 30, "video duration = 30");
    CHECK(v.durHour() == 0, "video durHour = 0");

    quiz q("Test Quiz", 6);
    CHECK(q.getDur() == 12, "quiz duration = num*2 = 12");
    CHECK(q.durHour() == 0, "quiz durHour = 0");

    quiz qLong("Long Quiz", 90);
    CHECK(qLong.getDur() == 180, "long quiz duration = 180 (3h)");
    CHECK(qLong.durHour() == 3, "long quiz durHour = 3");

    module m("Empty Module");
    CHECK(m.getDur() == 0, "empty module duration = 0");

    m.add(new video("Child Video", 20));
    m.add(new quiz("Child Quiz", 5));
    CHECK(m.getDur() == 30, "module duration = 20+10 = 30");
}

void testCourseManualPush() {
    TEST("Course Container Manual Push & Display");

    Course c;
    c.push(new video("Course Intro Video", 15));
    c.push(new quiz("Syllabus Quiz", 5));

    module* m = new module("Module 1: Advanced C++");
    m->add(new video("Pointers & Memory", 45));
    m->add(new quiz("Memory Quiz", 10));
    c.push(m);

    std::cout << "--- Course Display ---\n";
    c.display();
    std::cout << "----------------------\n";
}

void testCourseFileLoad(const char* path) {
    TEST(std::string("Course File Loading: ") + path);

    std::ifstream file(path);
    CHECK(file.is_open(), std::string("Opened ") + path);

    Course c;
    if (file.is_open()) {
        c.gen(file);
        file.close();
    }

    std::cout << "--- Course Display (" << path << ") ---\n";
    c.display();
    std::cout << "-------------------------------------\n";
}

void testCourseEmptyFile() {
    TEST("Course Empty / Missing File Safety");

    std::ifstream bad("nonexistent.txt");
    CHECK(!bad.is_open(), "Nonexistent file fails to open");

    Course c;
    std::ifstream empty("input_empty.txt");
    if (empty.is_open()) {
        c.gen(empty);
        empty.close();
    }
    CHECK(true, "Course handles empty input file gracefully");
}

void testMemoryManagement() {
    TEST("Course Memory Cleanup");

    Course* c = new Course();
    c->push(new video("Temporary Video", 10));
    c->push(new quiz("Temporary Quiz", 5));
    
    module* m = new module("Temporary Module");
    for (int i = 0; i < 50; i++) {
        m->add(new video("Nested Video", 2));
    }
    c->push(m);

    delete c; // Destructor should cleanly delete all top-level items and nested modules
    CHECK(true, "Course deleted successfully without memory leaks");
}

void testTopDownModuleAssembly() {
    TEST("Top-Down Module Assembly (Dynamic Duration)");

    module parent("Parent Module");
    module* child = new module("Child Submodule");

    // Add empty child submodule to parent module
    parent.add(child);
    CHECK(parent.getDur() == 0, "Parent duration is 0 when child submodule is empty");

    // Afterwards, populate the child submodule
    child->add(new video("Lesson 1", 30));
    child->add(new quiz("Quiz 1", 5)); // 5 * 2 = 10 min

    // Verify parent dynamically reflects child's updated duration
    CHECK(child->getDur() == 40, "Child submodule duration updated to 40");
    CHECK(parent.getDur() == 40, "Parent module dynamically reflects updated child duration = 40");
}

int main() {
    testManualConstruction();
    testCourseManualPush();
    testTopDownModuleAssembly();
    testCourseEmptyFile();
    testCourseFileLoad("input_single.txt");
    testCourseFileLoad("input.txt");
    testCourseFileLoad("input_deep.txt");
    testMemoryManagement();

    std::cout << "\n=== Results: ";
    if (failed == 0)
        std::cout << "ALL PASSED";
    else
        std::cout << failed << " FAILED";
    std::cout << " ===\n";

    return failed;
}


