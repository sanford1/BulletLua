-- BulletLua Test Script

dir = 0

function main()
    local turn = getTurn()
    local rank = getRank()

    if (math.fmod(turn, 15) == 0) then
        fire(dir, 1.5, explode)
        dir = dir + 34
    end
end

function explode()
    local turn = getTurn()
    if (turn == 60) then
        fireCircle(40, 4.0, homeIn)

        kill()
    end
end

function homeIn()
    local turn = getTurn()
    if (turn == 20) then
        setSpeed(1)
    elseif (turn == 25) then
        aimTarget()
        setSpeed(10)
    elseif (turn == 50) then
        vanish()
    end
end
