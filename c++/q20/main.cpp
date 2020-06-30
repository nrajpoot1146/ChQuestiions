int main()
{
   ArrayBag<std::string> bag;
   std::cout << "Testing the Array-Based Bag:" << std::endl;
   std::cout << "The initial bag is empty." << std::endl;
   bagTester(bag);
   std::cout << "All done!" << std::endl;
  
   return 0;
} // end main