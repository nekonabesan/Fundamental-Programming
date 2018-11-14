require 'bigdecimal'
require 'bigdecimal/util'
class FpModule

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
