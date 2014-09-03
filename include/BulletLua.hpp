#ifndef _BulletLua_hpp_
#define _BulletLua_hpp_

#include <string>
#include <memory>

#include <sol.hpp>

#include "Bullet.hpp"

class BulletLuaManager;

class BulletLua : public Bullet
{
    private:
        static BulletLua* current;

    public:
        BulletLua();

        void makeReusable(Bullet* target, BulletLuaManager* owner);

        void set(const std::string& filename,
                 Bullet* origin, Bullet* target,
                 BulletLuaManager* owner);

        // void set(std::shared_ptr<sol::state> lua,
        //          const std::string& func,
        //          Bullet* origin, Bullet* target,
        //          BulletLuaManager* owner);

        void set(std::shared_ptr<sol::state> lua,
                 const std::string& func,
                 float x, float y, float d, float s,
                 Bullet* target,
                 BulletLuaManager* owner);

        int getTurn() const;
        void run();

        void __debugRun(const std::string& code);

    private:
        void setFunctionName(const std::string& funcName);
        void initLua();

    private:
        Bullet* target;

        std::shared_ptr<sol::state> luaState;
        std::string funcName;

        int turn;

        BulletLuaManager* mOwner;
};

#endif // _BulletLua_hpp_
