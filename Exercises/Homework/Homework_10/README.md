# Homework 10

## Exercise 1

> Given all integers between *0* and *50*. Count how many ones (number *1* that is) the number has in binary. If the amount is *even* print the number. Otherwise don't print it. There is a binary converter in the lecture material.
>
> Example output =>  
> *0 3 5 6 9 10 12 15 17 18 20 23 24 27 29 30 33 34 36 39 40 43 45 46 48*

```cpp
#include <iostream>
#include <string>

std::string binary_number_to_str(const uint8_t binary_number)
{
    std::string binary_as_str = "0b"; // "0b" means zero binary
    const int bit_count = 8;

    for (int i = 0; i < bit_count; ++i) {
        const int bs = (bit_count - 1) - i;
        binary_as_str += std::to_string(static_cast<int>((binary_number & (1 << bs)) >> bs));
    }

    return binary_as_str;
}

int get_bit_value_count(const uint8_t binary_number, const char bit_value) {
    const std::string binary_as_str = binary_number_to_str(binary_number);

    int bit_value_count = 0;

    for (const auto& value : binary_as_str) {
        if (value == bit_value) {
            ++bit_value_count;
        }
    }

    return bit_value_count;
}

bool is_even(const int value){
    return value % 2 == 0;
}

int main()
{
    const int min = 0;
    const int max = 50;

    for (int i = min; i < max; ++i) {
        const int number_one_count = get_bit_value_count(i, '1');

        if (is_even(number_one_count)) {
            std::cout << i << " ";
        }
    }

    std::cout << "\n";

    return 0;
}
```

## Exercise 2

> Asks for user's *full_name* and *birth_year* in *main*. Make a function that creates a *Person struct*. Check when creating the *struct* that your data makes sense, so if e.g. name's length is *0* or birth year isn't between *1900* and *2019* then return a *null pointer* instead.
>
> In *main* call this function with the parameters you got from input and check with "if" if the function returned *null pointer* or pointer
to the *struct*; If it does, say "Creating person failed", otherwise print "Creating person successful". Remember to use *new* so that your pointer value doesn't get deleted due to the scope.

```cpp
#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include <utility>

struct Person {
    Person(const std::string full_name, const int birth_year) 
        : full_name{std::move(full_name)}, birth_year{birth_year}
    {
    }

    std::string full_name;
    int birth_year;
};

struct InputReader {
    template <typename T>
    static T read()
    {
        T value{};
        std::cin >> value;

        reset();

        return value;
    }
private:
    static void reset()
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
};

std::unique_ptr<Person> create_person(const std::string& full_name, const int birth_year)
{
    if (full_name.size() > 0 && (birth_year >= 1900 && birth_year <= 2019)) {
        return std::make_unique<Person>(full_name, birth_year);
    }

    return nullptr;
}

int main()
{
    std::cout << "What is your full name?\n";
    const std::string full_name = InputReader::read<std::string>();

    std::cout << "What is your birth year?\n";
    const int birth_year = InputReader::read<int>();

    const std::unique_ptr<Person> person = create_person(full_name, birth_year);

    if (person) {
        std::cout << "Creating person successful!\n";
    }
    else {
        std::cerr << "Creating person failed!\n";
        return -1;
    }

    return 0;
}
```

## Exercise 3

> Imagine we need to compress a deck of cards into as small space as possible. Before we have used a full *16 bit integer* for the type and another *16 bit integer* or even a *string* for the *suit* making it *32 bits* for a single card.
> 
> There are *52* possible cards so it should take only *6* bits to hold a single card. Let's settle for a *single byte* though for ease of use as *6 bits* handles difficulty with arrays or passing the cards into functions.
>
> Use a *bit field* with *unsigned ints* to hold the card values. *2 first bits for the suit*, *4 next bits for the value*. *Last 2 bits can be left unused*.

```cpp
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <unordered_map>

enum class Suit {
    hearts   = 0b0000'0000,
    diamonds = 0b0100'0000,
    spades   = 0b1000'0000,
    clubs    = 0b1100'0000
};

struct Card {
    // I dont like to have default construtor, but removing it stops the code from compiling;
    // The reason is that having a line such as `std::array<Card, N> cards_array;` will call this
    // constructor in order to fill the allocated array with default cards (design problem).
    Card() : Card{Suit::hearts, min()}
    {
    }

    Card(const Suit& suit, const int value) : packed_value_{to_packed_value(suit, value)}
    {
    }

    friend std::ostream& operator <<(std::ostream& os, const Card& other)
    {
        const std::string suit = other.readable_suit();
        const int value = other.value();

        if (value > other.ace_ && value < other.jack_) {
            os << value << " of " << suit;
        }
        else if (value == other.ace_) {
            os << "Ace of " << suit;
        }
        else if (value == other.jack_) {
            os << "Jack of " << suit;
        }
        else if (value == other.queen_) {
            os << "Queen of " << suit;
        }
        else if (value == other.king_) {
            os << "King of " << suit;
        }

        return os;
    }

    inline std::string readable_suit() const
    {
        return readable_suits_.at(suit());
    }

    constexpr static int min()
    {
        return ace_;
    }

    constexpr static int max()
    {
        return king_;
    }

    // This is fancy; basically what it does is to show that we can still access the real
    // binary value of suit by unsetting all the bits except the first two.
    constexpr Suit suit() const
    {
        return static_cast<Suit>(packed_value_ & 0b1100'0000);
    }

    // Here we do the same than above, but this time we remove the binary value of suit
    // to access the real integer value of this card. (four middle bits, shifted to right by 2).
    constexpr int value() const
    {
        return (packed_value_ & 0b0011'1100) >> 2;
    }
private:
    constexpr uint8_t to_binary_suit(const Suit& suit) const
    {
        return static_cast<uint8_t>(suit);
    }

    constexpr uint8_t to_binary_value(const int value) const
    {
        return static_cast<uint8_t>(value) << 2;
    }

    constexpr uint8_t to_packed_value(const Suit& suit, const int value) const
    {
        if (value < min() || value > max()) {
            return min();
        }

        return to_binary_suit(suit) | to_binary_value(value);
    }

    constexpr static int ace_   = 1;
    constexpr static int jack_  = 11;
    constexpr static int queen_ = 12;
    constexpr static int king_  = 13;

    inline static const std::unordered_map<Suit, std::string> readable_suits_ = {
        {Suit::hearts,   "Hearts"}, 
        {Suit::diamonds, "Diamonds"}, 
        {Suit::spades,   "Spades"}, 
        {Suit::clubs,    "Clubs"}
    };

    // Packing rules:
    // 
    // - Two first bits for the suit.
    // - four next bits for the value.
    // - Two last bits left unused.
    //
    // E.g. The packed value of "King of Spades" is 0b1011'0100, because:
    // 
    // - The binary value of Suit::spades is 0b1000'0000.
    // - The binary value of 13 (King) is 0b0000'1101.
    // - However, because we use "four next bits for the value"; the binary value of king
    //   is shifted left by 2, so from 0b0000'1101 to 0b0011'0100.
    // - And finally we add these together 0b1000'0000 + 0b0011'0100 = 0b1011'0100 ("King of Spades").
    uint8_t packed_value_;
};

template <std::size_t N>
struct Deck {
    Deck(const std::vector<Card>& cards) : cards_{to_cards_array(cards)}
    {
    }

    friend std::ostream& operator <<(std::ostream& os, const Deck& other)
    {
        for (const auto& card : other.cards_) {
            os << card << std::endl;
        }

        return os;
    }
private:
    std::array<Card, N> to_cards_array(const std::vector<Card>& cards) const
    {
        std::array<Card, N> cards_array;
        std::move(cards.begin(), cards.end(), cards_array.begin());

        return cards_array;
    }

    std::array<Card, N> cards_;
};

struct DeckCreator {
    DeckCreator() = delete;

    static Deck<52> poker()
    {
        std::vector<Card> cards;

        for (const auto& suit : {Suit::hearts, Suit::diamonds, Suit::spades, Suit::clubs}) {
            for (int value = Card::min(); value <= Card::max(); ++value) {
                cards.emplace_back(suit, value);
            }
        }

        return cards;
    }
};

int main()
{
    const Deck<52> poker_deck = DeckCreator::poker();

    std::cout << poker_deck << "\n"; // Debug

    std::cout << "Size information:\n"
              << "===============================\n"
              << "Size of one card: " << sizeof(Card{Suit::spades, 1}) << " byte(s).\n"
              << "Size of deck with 52 cards: " << sizeof(poker_deck) << " byte(s).\n"
              << "===============================\n";

    return 0;
}
```

**Output**

```
Ace of Hearts
2 of Hearts
3 of Hearts
4 of Hearts
5 of Hearts
6 of Hearts
7 of Hearts
8 of Hearts
9 of Hearts
10 of Hearts
Jack of Hearts
Queen of Hearts
King of Hearts
Ace of Diamonds
2 of Diamonds
3 of Diamonds
4 of Diamonds
5 of Diamonds
6 of Diamonds
7 of Diamonds
8 of Diamonds
9 of Diamonds
10 of Diamonds
Jack of Diamonds
Queen of Diamonds
King of Diamonds
Ace of Spades
2 of Spades
3 of Spades
4 of Spades
5 of Spades
6 of Spades
7 of Spades
8 of Spades
9 of Spades
10 of Spades
Jack of Spades
Queen of Spades
King of Spades
Ace of Clubs
2 of Clubs
3 of Clubs
4 of Clubs
5 of Clubs
6 of Clubs
7 of Clubs
8 of Clubs
9 of Clubs
10 of Clubs
Jack of Clubs
Queen of Clubs
King of Clubs

Size information:
===============================
Size of one card: 1 byte(s).
Size of deck with 52 cards: 52 byte(s).
===============================
```

## Exercise 4

> Our fancy *Nokia 3660* device has *16-bit* colors, *65536* possible colors in fact.
> 
> *The first 5 bits are for red color*, *next 6 for green* (human eye is more sensitive to the green color so that is why we spend the extra bit there) and the last *5 bits are for blue*.
>
> Make a program that converts our modern *24-bit color* into a *16-bit color*. *24-bit color* has *8 bits* for each color: *red*, *green* and *blue*. Remember of course that you need to adjust the maximum brightness as maximum value of *5 bits* is less than with *8 bits*.

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

struct BinaryFormatter {
    BinaryFormatter() = delete;

    static std::string to_str(const uint16_t value)
    {
        std::string str = "0b"; // "0b" means zero binary
        const int bit_count = 16;

        for (int i = 0; i < bit_count; ++i) {
            const int bs = (bit_count - 1) - i;
            str += std::to_string(static_cast<int>((value & (1 << bs)) >> bs));
        }

        return str;
    }
};

struct Color24; // Forward declaration to avoid compile time errors.

struct Color16 {
    Color16(const Color24& color24) : rgb_{to_16bit_color(color24)}
    {
    }

    friend std::ostream& operator <<(std::ostream& os, const Color16& other)
    {
        os << BinaryFormatter::to_str(other.rgb_);
        return os;
    }
private:
    /* constexpr */ uint16_t to_16bit_color(const Color24& color24) const;

    constexpr static int total_bits_ = 16;
    constexpr static int red_bits_   = 5;
    constexpr static int green_bits_ = 6;
    constexpr static int blue_bits_  = 5;

    // Packing rules:
    // 
    // - 5 first bits are for the (R)ed color.
    // - Next 6 bits are for the (G)reen color.
    // - And last 5 bits are for the (B)lue color. 
    //
    // In other words, uint16_t rgb_ = 0bRRRR'RGGG'GGGB'BBBB. (16 bits).
    uint16_t rgb_;
};

struct Color24 {
    Color24(const uint8_t red, const uint8_t green, const uint8_t blue)
        : red_{red}, green_{green}, blue_{blue}
    {
    }

    explicit inline operator Color16() const
    {
        return *this; // Calls `Color16(const Color24& color24)` constructor.
    }

    constexpr uint8_t red() const
    {
        return red_;
    }

    constexpr uint8_t green() const
    {
        return green_;
    }

    constexpr uint8_t blue() const
    {
        return blue_;
    }
private:
    uint8_t red_;
    uint8_t green_;
    uint8_t blue_;
};

// The method uses calls e.g. `color24.red()` and needs to be declared here to avoid compile time errors.
uint16_t Color16::to_16bit_color(const Color24& color24) const
{
    // When converting from 24 bits to 16 bits, we need to accept the "loss of color information".
    // Hence, this is done by shifting bits to the right for a smaller values.
    const uint8_t red   = color24.red()   >> (total_bits_ / 2 - red_bits_);
    const uint8_t green = color24.green() >> (total_bits_ / 2 - green_bits_);
    const uint8_t blue  = color24.blue()  >> (total_bits_ / 2 - blue_bits_);

    // The actual conversion to 0bRRRR'RGGG'GGGB'BBBB format. 
    return (red << (total_bits_ - red_bits_)) | (green << red_bits_) | blue;
}

int main()
{
    const Color24 red24{0xFF, 0x00, 0x00}; // 0xFF = 255
    const Color24 green24{0x00, 0xFF, 0x00};
    const Color24 blue24{0x00, 0x00, 0xFF};
    const Color24 teal24{0, 128, 128};
    const Color24 forest_green24{78, 146, 88};

    const Color16 red16 = static_cast<Color16>(red24);
    const Color16 green16{green24};
    const Color16 blue16 = blue24;
    const Color16 teal16 = static_cast<Color16>(teal24);
    const Color16 forest_green16 = static_cast<Color16>(forest_green24);

    std::cout << "red24 (0xFF, 0x00, 0x00) as red16 value is: "     << red16   << "\n"
              << "green24 (0x00, 0xFF, 0x00) as green16 value is: " << green16 << "\n"
              << "blue24 (0x00, 0x00, 0xFF) as blue16 value is: "   << blue16  << "\n"
              << "teal24 (0, 128, 128) as teal16 value is: "        << teal16  << "\n"
              << "forest_green24 (78, 146, 88) as forest_green16 value is: "   << forest_green16 << "\n\n";

    std::cout << "Size information:\n"
              << "===============================\n"
              << "Size of Color16: " << sizeof(Color16{{0x00, 0x00, 0x00}}) << " byte(s).\n"
              << "Size of Color24: " << sizeof(Color24{0x00, 0x00, 0x00}) << " byte(s).\n"
              << "===============================\n";

    return 0;
}
```

**Output**

```
red24 (0xFF, 0x00, 0x00) as red16 value is: 0b1111100000000000
green24 (0x00, 0xFF, 0x00) as green16 value is: 0b0000011111100000
blue24 (0x00, 0x00, 0xFF) as blue16 value is: 0b0000000000011111
teal24 (0, 128, 128) as teal16 value is: 0b0000010000010000
forest_green24 (78, 146, 88) as forest_green16 value is: 0b0100110010001011

Size information:
===============================
Size of Color16: 2 byte(s).
Size of Color24: 3 byte(s).
===============================
```
