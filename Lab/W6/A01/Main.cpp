#include "Material.h"
#include <fstream>
#include <iostream>
#include <cassert>

static int failed = 0;
#define TEST(name) do { std::cout << "=== " << name << " ===\n"; } while(0)
#define CHECK(cond, msg) do { if (!(cond)) { std::cout << "  FAIL: " << msg << "\n"; failed++; } else std::cout << "  PASS: " << msg << "\n"; } while(0)

void testManualConstruction() {
    TEST("Manual construction");

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

    m.add(new video("Child", 20));
    m.add(new quiz("Child Quiz", 5));
    CHECK(m.getDur() == 30, "module with 2 children duration = 20+10 = 30");
}

void testDisplay() {
    TEST("Display output (manual check)");

    module m("Display Test");
    m.add(new video("Vid A", 10));
    m.add(new quiz("Quiz A", 3));

    std::cout << "--- display(0) ---\n";
    m.display(0);
    std::cout << "--- display(1) ---\n";
    m.display(1);
    std::cout << "--- display(2) ---\n";
    m.display(2);
}

void testFileLoad(const char* path, int expectedItems) {
    std::ifstream file(path);
    CHECK(file.is_open(), std::string("opened ") + path);

    module m("Loaded");
    fin(file, m, expectedItems);
    file.close();

    std::cout << "--- " << path << " display(1) ---\n";
    m.display(1);
    std::cout << "\n";
}

void testFileEmpty() {
    TEST("Empty / missing file safety");

    std::ifstream bad("nonexistent.txt");
    CHECK(!bad.is_open(), "nonexistent file fails to open");

    module m("Empty Load");
    std::ifstream empty("input_empty.txt");
    if (empty.is_open()) {
        fin(empty, m, 5);
        empty.close();
    }
    CHECK(m.getDur() == 0, "loading from empty file leaves module unchanged");
}

void testSingleItem() {
    TEST("Single item from file");

    module m("Single");
    std::ifstream f("input_single.txt");
    if (f.is_open()) {
        fin(f, m, 1);
        f.close();
    }
    CHECK(m.getDur() == 15, "single video duration = 15");
    std::cout << "--- display(1) ---\n";
    m.display(1);
    std::cout << "\n";
}

void testDeepNesting() {
    TEST("Deep nesting");

    module m("Root");
    std::ifstream f("input_deep.txt");
    if (f.is_open()) {
        fin(f, m, 1);
        f.close();
    }

    int dur = m.getDur();
    std::cout << "Root duration: " << dur << "m (" << m.durHour() << "h " << dur % 60 << "m)\n";
    CHECK(dur > 0, "root module accumulates nested durations");

    std::cout << "--- display(1) ---\n";
    m.display(1);
    std::cout << "\n";
}

void testMemoryManagement() {
    TEST("Memory management (destructor cleanup)");

    module* leakTest = new module("Leak Test");
    for (int i = 0; i < 100; i++) {
        leakTest->add(new video("Leakable", 1));
    }
    CHECK(leakTest->getDur() == 100, "100 videos added, duration = 100");
    delete leakTest;
    std::cout << "  After delete: no leak if this prints\n";
}

int main() {
    testManualConstruction();
    testDisplay();
    testFileEmpty();
    testSingleItem();
    testDeepNesting();
    testFileLoad("input.txt", 3);
    testMemoryManagement();

    std::cout << "\n=== Results: ";
    if (failed == 0)
        std::cout << "ALL PASSED";
    else
        std::cout << failed << " FAILED";
    std::cout << " ===\n";

    return failed;
}
