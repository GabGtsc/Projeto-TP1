#pragma once
#include <string>

class Data {
private:
  int dia_, mes_, ano_;

public:
  Data() = default;
  Data(const std::string &data);
  void setData(const std::string &data);
  [[nodiscard]] std::string getData() const;
};
