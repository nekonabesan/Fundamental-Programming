=begin
演習 3 有理数クラスをそのまま打ち込んで動かせ。
動いたら、四則の他の演算も追加し、動作を確認せよ。
できれば、これを用いて浮動小数点では正確に行えない「実用的な」計算が正確にで
きることを確認してみよ。
=end
class Ratio
  begin
    def initialize(a, b = 1)
      if b == 0 then
        @a = 1
      end
      if a == 0 then
        @b = 1;
      end
      @a = a.to_i
      @b = b.to_i
      if b < 0 then
        @a = -a
        @b = -b
      end
      g = gcd(a.abs, b.abs)
      @a = @a/g
      @b = @b/g
    rescue => e
      return e
    end
  end

  def getDivisor
    return @b
  end

  def getDividend
    return @a
  end

  def to_s
    return "#{@a}/#{@b}"
  end

  def add(r)
    begin
      raise ArgumentError if r == nil
      c = r.getDividend
      d = r.getDivisor
      # a/b+c/d = (ad+bc)/bd
      return Ratio.new(@a*d + @b*c, @b*d)
    rescue => e
      return e
    end
  end

  def subtraction(r)
    begin
      raise ArgumentError if r == nil
      c = r.getDividend
      d = r.getDivisor
      # a/b-c/d = (ad-bc)/bd
      return Ratio.new(@a*d - @b*c, @b*d)
    rescue => e
      return e
    end
  end

  def times(r)
    begin
      raise ArgumentError if r == nil
      return Ratio.new(@a*r.getDividend, @b*r.getDivisor)
    rescue => e
      return e
    end
  end

  def div(r)
    begin
      raise ArgumentError if r == nil
      return Ratio.new(@a*r.getDivisor, @b*r.getDividend)
    rescue => e
      return e
    end
  end

  def gcd(x, y)
    begin
      raise ArgumentError if x == nil || y == nil
      while true do
        if x > y then
          x = x % y
          if x == 0 then
            return y
          end
        else y = y % x
          if y == 0 then
            return x
          end
        end
      end
      return TRUE
    rescue => e
      return e
    end
  end
end
