#pragma once

#include <iostream>
#include <functional>

/// @brief Read-only C# style properties.
/// @tparam T The type of this property.
template <typename T>
struct computed_prop
{
    /// @brief The type of this property.
    using type = T;
    /// @brief The type of the getter function.
    using getter_type = std::function<const type &(void)>;

    /// @brief Constructs a new computed property by specified getter.
    /// @param getter The specified getter function.
    computed_prop(getter_type getter) : getter(getter) {}

    /// @brief Constructs a new computed property by capturing the specified field.
    /// @param field The specified field.
    computed_prop(type &field)
        : getter([&](void) -> const int &
                 { return field; })
    {
    }

    /// @brief Implict conversion implimenting the getter for this property.
    operator type() const { return getter(); }

private:
    /// @brief The getter function.
    getter_type getter;
};

/// @brief Prints the value of the specified property.
/// @tparam T The type of the property.
/// @param os The output stream.
/// @param prop The specified property.
/// @return The output stream after property printed.
template <typename T>
std::ostream &operator<<(std::ostream &os, const computed_prop<T> &prop)
{
    return os << static_cast<T>(prop);
}

/// @brief Write-only C# style properties.
/// @tparam T The type of this property.
template <typename T>
struct write_prop
{
    using type = T;
    using setter_type = std::function<void(const type &)>;

    write_prop(setter_type setter) : setter(setter) {}

    write_prop(type &field)
        : setter([&](const int &value)
                 { field = value; })
    {
    }

    void operator=(const type &value) { setter(value); }

private:
    setter_type setter;
};

template <typename T>
struct property : public computed_prop<T>, public write_prop<T>
{
    using type = T;
    using getter_type = computed_prop<type>::getter_type;
    using setter_type = write_prop<type>::setter_type;

    property(getter_type getter, setter_type setter) : computed_prop<T>(getter), write_prop<T>(setter) {}
    property(type &field) : computed_prop<type>(field), write_prop<type>(field) {}
};

/// @brief Inplimentation of C# style properties.
/// This type of property is accessiable public but modifiable only in the owner class.
/// @tparam T The type of the property.
/// @tparam O The the property owner type. This type is able to modify this property.
template <typename T, class O>
struct readonly_field
{
    /// @brief The type of this property.
    using type = T;

    /// @brief Makes friendship with the property owner type.
    friend O;

    /// @brief Implict conversion implimenting the getter for this property.
    operator type() const { return data; }

    type &operator->() { return data; }
    const type &operator->() const { return data; }

private:
    /// @brief Default constructor.
    readonly_field() = default;

    /// @brief Conversion constructor.
    /// @param data The value of the property.
    readonly_field(const type &data) : data(data) {}

    /// @brief Setter for this property.
    /// @param value The specified property value.
    /// @return The new value of this property.
    type &operator=(type value) { return data = value; }

    /// @brief Value of this property.
    type data;
};

template <typename T, class O>
std::ostream &operator<<(std::ostream &os, const readonly_field<T, O> &prop)
{
    return os << static_cast<T>(prop);
}
