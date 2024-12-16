#include <iostream>
#include <memory>

// Інтерфейс принтера
class IPrinter {
public:
    virtual ~IPrinter() = default;
    virtual void print(const std::string& document) = 0;
};

// Інтерфейс сканера
class IScanner {
public:
    virtual ~IScanner() = default;
    virtual std::string scan() = 0;
};

// Клас, який реалізує тільки принтер
class SimplePrinter : public IPrinter {
public:
    void print(const std::string& document) override {
        std::cout << "Printing: " << document << std::endl;
    }
};

// Клас, який реалізує тільки сканер
class SimpleScanner : public IScanner {
public:
    std::string scan() override {
        return "Scanned document content";
    }
};

// Клас "розумне МФУ", яке і друкує, і сканує
class MultiFunctionDevice : public IPrinter, public IScanner {
public:
    void print(const std::string& document) override {
        std::cout << "MFD printing: " << document << std::endl;
    }

    std::string scan() override {
        return "MFD scanned document content";
    }
};

int main() {
    std::unique_ptr<IPrinter> printer = std::make_unique<SimplePrinter>();
    printer->print("Hello World!");

    std::unique_ptr<IScanner> scanner = std::make_unique<SimpleScanner>();
    std::cout << "Scanned: " << scanner->scan() << std::endl;

    std::unique_ptr<IPrinter> mfPrinter = std::make_unique<MultiFunctionDevice>();
    std::unique_ptr<IScanner> mfScanner = std::make_unique<MultiFunctionDevice>();

    mfPrinter->print("ISP Example Document");
    std::cout << "MFD Scan Result: " << mfScanner->scan() << std::endl;

    return 0;
}
