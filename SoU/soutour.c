/* FLOW CHART
Main menu
    1->language
      i   ->Book Tickets    ->Date&Time (condition monday is off-day)     ->NumberOfPersons ->Listing->Booking->Billings
      ii  ->About SoU       ->Places to visit->about the places
      iii ->Help & Support

*/
#include<stdio.h>
#include<string.h>
void helpSupportHINDI();
void helpSupportENGLISH();
void bookTicketsHINDI();
void bookTicketsENGLISH();
void aboutSoUHINDI();
void aboutSoUENGLISH();
void mainmenuHINDI();
void mainmenuENGLISH();
// Function to handle ticket bookings in Hindi
void bookTicketsHINDI()
{
  int day;
  int persons;
  int priseperseat=3000;
  int booking;
  int billings;

  printf("Kripya date aur time daalen:\n");
  scanf("%d", &day);
  if (day == 1) {
    printf("Maafi hai, somvaar off-day hai. Kripya doosra din chunen.\n");
  } else {
    printf("Kripya logon ki sankhya daalen:\n");
    scanf("%d", &persons);
    printf("Aapka booking confirm ho gaya hai.\n");
    printf("Aapka bill Rs.%d hai.\n", persons * priseperseat);
  }
}
// Function to display information about SoU in Hindi
void aboutSoUHINDI()
{
  int place;

  printf("SoU ek sundar jagah hai jismein bahut saare anokhe sthan hain jo dekhne ke liye achche hain.\n");
  printf("Yahaan kuchh hamare top recommendations hain:\n");
  printf("1. Museum\n");
  printf("2. Park\n");
  printf("3. Art gallery\n");
  printf("Aap kaun sa sthan jaanna chahte hain?\n");
  scanf("%d", &place);
  if (place == 1) {
    printf("Museum ek lokpriya sthan hai jo art aur itihaas ke pramaanikon ki collection rakhta hai.\n");
  } else if (place == 2) {
    printf("Park ek shaanti ka sthan hai jahaan aap apni shaanti aur prakriti ke saath nirbhik hokar anand le sakte hain. Ismein ek talab, chalne ke raaste, aur bahut saare ped aur paudhe hain.\n");
  } else if (place == 3) {
    printf("Art gallery ek achcha sthan hai jahaan aap desh ke aur videsh ke kalaakaaron ke kai prakaar ke paintings, sculptures, aur doosre kalaakaaritaayon ko dekh sakte hain.\n");
  } else {
    printf("Galat chunaav.\n");
    aboutSoUHINDI();
  }
}
// Function to provide help and support in Hindi
void helpSupportHINDI()
{
  printf("Kripya apna sawal likhen:\n");
  // Provide help and support based on the user's question
}
// Function to display information about SoU in English
void aboutSoUENGLISH()
{
  int place;

  printf("SoU is a beautiful place with many interesting places to visit.\n");
  printf("Here are some of our top recommendations:\n");
  printf("1. Museum\n");
  printf("2. Park\n");
  printf("3. Art gallery\n");
  printf("Which place would you like to learn more about?\n");
  scanf("%d", &place);
  if (place == 1) {
  printf("The museum is a popular place that holds authentic collections of art and history.\n");
  } else if (place == 2) {
  printf("The park is a peaceful place where you can find solace and enjoyment in nature. It has a lake, walking paths, and many trees and plants.\n");
  } else if (place == 3) {
  printf("The art gallery is a great place to see various types of paintings, sculptures, and other artworks by local and international artists.\n");
  } else {
  printf("Invalid selection.\n");
  aboutSoUENGLISH();
  }
}
// Function to handle ticket bookings in English
void bookTicketsENGLISH()
{
  int day;
  int persons;
  int priseperseat;
  int booking;
  int billings;

  printf("Please enter the date and time:\n");
  scanf("%d", &day);
  if (day == 1) {
    printf("Sorry, Monday is an off-day. Please select a different day.\n");
  } else {
    printf("Please enter the number of persons:\n");
    scanf("%d", &persons);
    printf("Your booking has been confirmed.\n");
    printf("Your bill is $%d.\n", persons * priseperseat);
  }
}
// Function to display the main menu in English
void mainmenuENGLISH()
{
  int option;

  // Display the main menu in English
  printf("WELCOME to the booking facility of SoU!!\n");
  printf("Please select an option from the main menu:\n");
  printf("1. Book tickets\n");
  printf("2. About SoU\n");
  printf("3. Help & support\n");
  scanf("%d", &option);

  // Call the appropriate function based on the user's selection
  switch (option) {
    case 1:
      bookTicketsENGLISH();
      break;
    case 2:
      aboutSoUENGLISH();
      break;
    case 3:
      helpSupportENGLISH();
      break;
    default:
      printf("Invalid selection.\n");
      mainmenuENGLISH();
      break;
  }
}
// Function to provide help and support in English
void helpSupportENGLISH()
{
  printf("Please enter your question:\n");
  mainmenuENGLISH();
  // Provide help and support based on the user's question
}
// Function to display the main menu in Hindi
void mainmenuHINDI()
{
  int option;

  // Display the main menu in Hindi
  printf("SoU ke ticket booking kedra me aap ka swagat hai!!\n");
  printf("Mukhya menu mein se koi ek option chunen:\n");
  printf("1. Ticket book karen\n");
  printf("2. SoU ke bare mein jaankari\n");
  printf("3. Sahayata aur support\n");
  scanf("%d", &option);

  // Call the appropriate function based on the user's selection
  switch (option) {
    case 1:
      bookTicketsHINDI();
      break;
    case 2:
      aboutSoUHINDI();
      break;
    case 3:
      helpSupportHINDI();
      break;
    default:
      printf("Invalid selection.\n");
      mainmenuHINDI();
      break;
  }
}
//Main function of the programm
int main()
{
  int lang;

  printf("\nFor Hindi enter 1 \nFor English enter 2\n");
  scanf("%d",&lang);
  if (lang == 1) {
    mainmenuHINDI();
  } else if (lang == 2) {
    mainmenuENGLISH();
  } else {
    printf("Invalid selection.\n");
    main();
  }

  return 0;
}
