#include <set>
#include <list>
#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono;

#define MAX_NUMBER_EMAILS 100000
#define MICRO_TO_SEC 1000000
#define EMAILSTR "thisisjustpadding@gmail.com"
#define DUPEMAILSTR "duplicate@gmail.com"


/**
 Function to remove duplicates from list
 Input  : std::list& (doubly linked list )of emails that may contain duplicates, passed by address
 Output : void 
 * */

void removeDuplicates(std::list<std::string>& emails){
    // Container to store unique emails
    std::set<std::string> uniqueEmails;
    for(auto it = emails.begin(); it != emails.end();){
        // If not in container then non-duplicate email, so add to container and go to next item
        if(uniqueEmails.find(*it) == uniqueEmails.end()){
            uniqueEmails.insert(*it);
            it ++;
        }else{ // In case of duplicate, erase from linked_list and update the iterator
            it = emails.erase(it); 
        }
    }

}


// Helper function to populate email list passed by address
// Input : int count - Total number of emails to add in list;  
//         std::list - empty list, passed by address ; 
//         bool allDuplicate - default false, adds unique emails; if true then adds all duplicate 
// Output : void
void prepareEmailList(int count,std::list<std::string>& list, bool allDuplicate = false){
    for(int i = count; i > 0 ; i--){ 
        if(allDuplicate){
            list.push_back(DUPEMAILSTR);
        }else{
            list.push_back(std::to_string(i) + EMAILSTR);     
        }
    }
}


// Test helper function , to return list of emails with no duplicates
std::list<std::string> test_helper_no_dups(){
    std::list<std::string> no_dup_list;
    prepareEmailList(MAX_NUMBER_EMAILS,no_dup_list);
    return no_dup_list;
}


// Test helper function , to return list of emails with 50% duplicates
std::list<std::string> test_helper_half_dups(){
    std::list<std::string> half_dup_list;
    // Call it twice so we will get duplicate list
    prepareEmailList(MAX_NUMBER_EMAILS/2,half_dup_list);
    prepareEmailList(MAX_NUMBER_EMAILS/2,half_dup_list);
    return half_dup_list;
}

// Test helper function , to return list of emails all duplicates
std::list<std::string> test_helper_all_dups(){
    std::list<std::string> all_dup_list;
    prepareEmailList(MAX_NUMBER_EMAILS,all_dup_list,true);
    return all_dup_list;
}


// Test helper function - to calculate function latency
void Test(std::list<std::string>& input_list, float& time_taken){
    auto start = high_resolution_clock::now();
    removeDuplicates(input_list);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    time_taken = (float)duration.count()/ MICRO_TO_SEC ;
}


int main (){
    std::list<std::string> email_list; 
    float time_taken = 0.0;
    // No Duplicate Test
    email_list = test_helper_no_dups();
    Test(email_list,time_taken);
    // No duplicate list should remain as it was
    if(email_list == test_helper_no_dups()){
        std::cout << "No Duplication Test Passed - Time Taken :"<< time_taken << " Seconds"<< std::endl;
    }else{
        std::cout << "Failed" <<std::endl;
    }

    // Half Duplicate Test
    email_list = test_helper_half_dups();
    Test(email_list,time_taken);
    // Vlidator test
    std::list<std::string> result_list;
    prepareEmailList(MAX_NUMBER_EMAILS/2,result_list);
    // Half duplicate list should match result_list 
    if(email_list == result_list){
        std::cout << "Half Duplication Test Passed - Time Taken :"<< time_taken << " Seconds"<< std::endl;
    }else{
        std::cout << "Failed" <<std::endl;
    }

    // All Duplicate Test
    email_list = test_helper_all_dups();
    Test(email_list,time_taken);
    // All duplicate list should have size 1, since there is only one uniqie email address
    if(email_list.size() == 1){
        std::cout << "All Duplication Test Passed - Time Taken :"<< time_taken << " Seconds"<< std::endl;
    }else{
        std::cout << "Failed" <<std::endl;
    }



}