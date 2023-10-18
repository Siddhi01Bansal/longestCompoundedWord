# Problem Statement
    -Reads provided files (Input_01.txt and Input_02.txt) containing alphabetically sorted words list (one
    word per line, no spaces, all lower case).
    -Identifies & display below given data in logs/console/output file
        -longest compounded word
        -second longest compounded word
        -time taken to process the input file
    -Note: A compounded word is one that can be constructed by combining (concatenating) shorter words
    also found in the same file.

# Instructions to run Project
    -Make sure you have CodeBlocks installed in your system along with environment setup to run CPP file.
    -Clone the repository.
    -For CodeBlocks, Press `F9` or click "Build and run" button.
    -You can use any code Editor as per your convenience.

# Approach and Algorithm
    -Read input file and push all the words in a vector.
    -While reading each word , build a trie data structure.
    -Initialized a queue of pair<word,suffix> and create it with valid words.
    -Initialize variables for the maxlen, longestWord, secLongestWord.
    -Continue the process until the queue is empty
        -Check if the suffix of the word contains any valid word from the trie.
            -If the length of the word is greater than the max_len then update secLongestWord with longestWord and longestWord with this word.
            -If not, generate suffix for each prefix length and push it to the queue <word,suffix>
        -If the suffix doesn't contain any valid prefix, discard the pair.
    -Print the longestWord and secLongestWord.

# Time Complexity
    O(KN) where K is the maximum number of words in a compound word.