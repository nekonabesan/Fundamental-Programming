require 'fiddle'
=begin
演習 3 クラス Buffer を打ち込み、動作を確認せよ。動いたら、以下の操作 (メソッド) を追加して
みよ。
=end
class Buffer
  Cell = Struct.new(:data, :next)

  def initialize
    @tail = @cur = Cell.new("EOF", nil)
    @head = @prev = Cell.new("HEAD", @cur)
  end

  def atend
    begin
      return @cur == @tail
    rescue => e
      return e
    end
  end

  def top
    begin
      @prev = @head
      @cur = @head.next
    rescue => e
      return e
    end
  end

  def forward
    begin
      return if atend
      @prev = @cur
      @cur = @cur.next
    rescue => e
      return e
    end
  end

  def insert(s)
    begin
      raise ArgumentError if s.nil?
      @prev.next = Cell.new(s, @cur)
      @prev = @prev.next
    rescue => e
      return e
    end
  end

  def print
    begin
      #puts(" " + @cur.data)
      return @cur.data
    rescue => e
      return e
    end
  end

=begin
a. 現在行を削除する (EOF 行は削除しないように注意…)
=end
  def a
    begin
      if @cur.data != "EOF" then
        nxt = @cur.next
        @cur = nil
        @cur = @prev
        @cur.next = nxt
        return true
      else
        return "EOF"
      end
    rescue => e
      return e
    end
  end

=begin
b. 現在行と次の行の順序を交換する (EOF は交換しないように…)
=end
  def b
    begin
      return "EOF" if @cur.next.data == "EOF"
      if @cur.next.data != "EOF" then
        buf = @cur
        nxt = buf.next.next
        @cur = buf.next
        @cur.next = buf
        @cur.next.next = nxt
      end
      return true
    rescue => e
      return e
    end
  end

=begin
c. 1 つ前の行に戻る (実は大変かも)
=end
  def c
    begin
      return true if @prev.data == "HEAD"
      buf = Fiddle::Pointer[@cur.data].to_i
      self.top
      while true do
        break if buf == Fiddle::Pointer[@cur.next.data].to_i
        self.forward
      end
      return true
    rescue => e
      return e
    end
  end


=begin
d. すべての行の順番を逆順にする (かなり過激)
=end
  def d
    begin
      a = Array.new
      self.top
      a.push(@cur.data)
      while true do
        self.forward
        a.push(@cur.data)
        break if @cur.next.data == "EOF"
      end
      len = a.length - 1
      self.top
      for i in 0..len do
        @cur.data = a[len - i]
        self.forward
      end
      self.top
      return true
    rescue => e
      return e
    end
  end
end
