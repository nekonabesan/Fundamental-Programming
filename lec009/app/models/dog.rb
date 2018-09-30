=begin
演習 1 この例題を打ち込み動かせ。次に「ほえる」メソッド bark(引数無) と、「ほえる回数」を設
定するメソッド setcount(回数を渡す) を追加せよ。最初は 3 回ほえるものとする。
=end
class Dog

  def initialize(name)
    @name = name
    @speed = 0.0
    @count = 0
  end

  def setName(name)
    @name = name
  end
  def getName
    return @name
  end

  def setSpeed(speed)
    @speed = speed
  end
  def getSpeed
    return @speed
  end

  def setCount(count)
    @count = count
  end
  def getCount
    return @count
  end

  def talk
    return 'my name is ' + @name
  end

  def addspeed(d)
    @speed = @speed + d
    return 'speed = ' + @speed.to_s
  end

  def bark
    @count.to_i.times{ |i| puts(i) }
  end
end
