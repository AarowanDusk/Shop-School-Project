#include "../public/Shop.h"

void shop::assignValues() {
  rapidcsv::Document doc("../data/bookDetails.csv", rapidcsv::LabelParams(0,
    0));
  std::vector < int > id = doc.GetColumn < int > ("Id");
  std::vector < std::string > names = doc.GetColumn < std::string > ("Names");
  int size = id.size();
  for (int i = 0; i < size; i++) {
    booksDetals.insert({
      id,
      names
    });
  }
}
void shop::getUsers() {
  rapidcsv::Document doc("../data/users.csv", rapidcsv::LabelParams(0, 0));
  std::vector < int > id = doc.GetColumn < int > ("Id");
  std::vector < std::string > pass = doc.GetColumn < std::string > ("Pass");
  int size = id.size();
  for (int i = 0; i < size; i++) {
    userDetails.insert({
      id,
      pass
    });
  }
}
bool shop::checkIfValudUser() {
  std::vector < int > id;
  int uId;
  std::vector < std::string > pass;
  std::string uPass;
  std::cout << std::endl << "Please enter user ID :" << std::endl;
  std::cin >> uId;
  id.insert(id.begin(), uId);
  std::cout << std::endl << "Please insert password :" << std::endl;
  std::cin >> uPass;
  pass.insert(pass.begin(), uPass);
  auto userData = userDetails.find(id);
  if (userData == userDetails.end()) {
    std::cout << std::endl << "No user found." << std::endl;
    return false;
  } else {
    if (userData -> second == pass) {
      std::cout << std::endl << "Log-in successful." << std::endl;
      return true;
    } else {
      std::cout << std::endl << "Wrong password." << std::endl;
      return false;
    }
  }
}
void shop::viewList() {
  std::cout << std::endl << "The list of available books are :" << std::endl;
  for (auto i = booksDetals.begin(); i != booksDetals.end(); i++) {
    std::cout << std::endl;
    for (auto j = i -> first.begin(); j != i -> first.end(); j++) {
      std::cout << * j << ".";
      for (auto k = i -> second.begin(); k != i -> second.end(); k++) {
        std::cout << * k;
      }
    }
    std::cout << std::endl;
  }
}
void shop::registerBook() {
  shop::viewList();
  std::vector < int > id;
  int bId;
  std::cout << std::endl << "Please insert Id against the book to register the
  book to inventory: "<<std::endl;
  std::cin >> bId;
  id.insert(id.begin(), bId);
  auto bookData = registeredBooks.find(id);
  if (bookData == userDetails.end()) {
    auto findName = booksDetals.find(id);
    if (findName == booksDetals.end()) {
      std::cout << "Error occured";
    } else {
      booksDetals.insert({
        id,
        findName -> second
      });
    }
  } else {
    std::cout << std::endl << "Book already registered or if this is an error
    please contact system admin.
    "<<std::endl;
  }
}
void shop::viewRegisteredList() {
  std::cout << std::endl << "The list of registered books are :" << std::endl;
  for (auto i = registeredBooks.begin(); i != registeredBooks.end(); i++) {
    std::cout << std::endl;
    for (auto j = i -> first.begin(); j != i -> first.end(); j++) {
      std::cout << * j << ".";
      for (auto k = i -> second.begin(); k != i -> second.end(); k++) {
        std::cout << * k;
      }
    }
    std::cout << std::endl;
  }
}
void shop::options() {
  std::cout << std::endl << "Please select :" << std::endl;
  std::cout << std::endl << "1.View list of books" << std::endl << "2.Register
  book "<<std::endl<<"
  3. View Registered books "<<std::endl;
  std::cout << std::endl << "Please make your choice :" << std::endl;
  int sw;
  std::cin >> sw;
  switch (sw) {
  case 1: {
    shop::viewList();
    shop::recursion();
    break;
  }
  case 2: {
    shop::registerBook();
    shop::recursion();
    break;
  }
  case 3: {
    shop::viewRegisteredList();
    shop::recursion();
    break;
  }
  default: {
    std::cout << "Error entry.";
    shop::recursion();
    break;
  }
  }
}
void shop::recursion() {
  std::cout << std::endl << "Please login as an user." << std::endl;
  bool uCheck = checkIfValudUser();
  while (uCheck != true) {
    uCheck = checkIfValudUser();
  }
  if (uCheck == true) {
    shop::options();
  }
}
int main() {
  std::cout << std::endl << "Starting BookShop management minisystem:" << std::endl;
  std::cout << std::endl;
  shop x;
  x.assignValues();
  x.getUsers();
  x.recursion();
  return 0;
}