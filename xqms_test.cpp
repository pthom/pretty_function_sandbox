#include "detail/type_name_xqms_wip.hpp"
//#include "detail/type_name_stringliteral.hpp"
// namespace type_name_details = boost::hana::experimental::type_name_details;


#define MAKE_STRING_SEQUENCE(...) \
    std::integer_sequence<char, __VA_ARGS__>

#define ASSERT_TYPES_EQUAL(T, U) \
    static_assert( std::is_same<T, U>(), "" )

#define ASSERT_TYPE_NAME(TypeSequence, T) \
    static_assert( std::is_same< decltype(TypeSequence) , T>(), "" )

// Helper macros that will output an intentional compiling error
// in which you can read a type
// Use them during development in order to display string sequences
// in the compiler output by creating an intentional error.
// Advice: pipe the compiler output to sed like this:
//       make 2>&1| sed s/"', '"//g
#define COMPILER_OUTPUT_VAR_TYPE(var) { var.IntentionalError = 42; }
#define COMPILER_OUTPUT_TYPE(T) { T::IntentionalError = 42; }

template<typename... T>
struct Foo {};

int main() {
    {
        auto t = detail::xqms_type_name<int>();
        ASSERT_TYPE_NAME(t, MAKE_STRING_SEQUENCE('i', 'n', 't') );
    }
    {
        // Todo : find a way to better construct a string sequence
        // (MAKE_STRING_SEQUENCE is difficult to read & write)
        auto t = detail::xqms_type_name< Foo<int> >();
        //COMPILER_OUTPUT_VAR_TYPE(t);
        ASSERT_TYPE_NAME(
            t,
            MAKE_STRING_SEQUENCE('F', 'o', 'o', '<', 'i', 'n', 't', '>') );
    }
    {
        auto t = detail::xqms_type_name< Foo<int, char> >();
        //COMPILER_OUTPUT_VAR_TYPE(t);
        ASSERT_TYPE_NAME(
            t,
            MAKE_STRING_SEQUENCE('F', 'o', 'o', '<', 'i', 'n', 't', ',', ' ', 'c', 'h', 'a', 'r', '>') );
    }
}
