#pragma once

#include <vector>
#include <algorithm>
#include <memory>

#include <iostream>

template <typename T>
class Owner
{
public:
    virtual ~Owner() = default;

    std::vector<std::unique_ptr<T>>& GetOwnees() { return Ownees; }

    const std::vector<std::unique_ptr<T>>& GetOwnees() const { return Ownees; }

    template <typename... Args>
    T* Emplace(Args&&... args) {
        Ownees.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
        return Ownees.back().get();
    }

    void CleanUp() {
        auto DeleteLambda = [&](auto & obj) { return obj->ShouldDelete(); };
        Ownees.erase(std::remove_if(Ownees.begin(), Ownees.end(), DeleteLambda), Ownees.end()); 
    }

protected:
    std::vector<std::unique_ptr<T>> Ownees;
};
