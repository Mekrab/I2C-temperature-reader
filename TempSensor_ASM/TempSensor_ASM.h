/*
 * Global register variable
 */
#ifdef __ASSEMBLER__

#else /*!Assembler*/

/* C-only stuff */
extern "C" {
  //Allows the C program to reference these assembly functions
  void read_temp();//set function
}

#endif /* ASSEMBLER */
