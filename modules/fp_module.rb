require 'bigdecimal'
require 'bigdecimal/util'
class FpModule
  #/-----------------------------------------------------------/
  # 正の整数 N を受け取り、N が素数なら true、
  # そうでなければ false を返す Ruby プログラム
  # return bool
  #/-----------------------------------------------------------/
  def judgePno(n)
    begin
      raise ArgumentError if n == nil || n == 0
      n = n.to_i.abs
      for i in 2..(n - 1) do
        return false if (n % i) == 0
      end
      return true
    rescue => e
      return e
    end
  end

  #/-----------------------------------------------------------/
  # 第8講
  # return int 実行時間
  #/-----------------------------------------------------------/
  def  bench(count = 1)
    begin
      t1 = Process.times.utime
      count.times do yield end #← count 回繰り返し yield を実行
        t2 = Process.times.utime
        return t2-t1
      rescue => e
        return e
      end
  end

  #/-----------------------------------------------------------/
  # 第7講
  # 議事乱数から生成された配列を返すメソッド
  # return Array(int)
  #/-----------------------------------------------------------/
  def randarray(n)
    begin
      return Array.new(n) do rand(10000) end
    rescue => e
      return e
    end
  end
end
