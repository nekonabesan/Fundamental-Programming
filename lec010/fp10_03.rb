require __dir__ + '/app/model/buffer.rb'

def edit
  e = Buffer.new
  while true do
    printf(">")
    line = gets; c = line[0..0]; s = line[1..-2]
    if c == "q" then return
    elsif c == "t" then e.top; e.print
    elsif c == "p" then e.print
    elsif c == "i" then e.insert(s)
    # elsif c == "r" then e.read(s)
    # elsif c == "w" then e.save(s)
    # elsif c == "s" then e.subst(s); e.print
    # elsif c == "d" then e.delete
    else e.forward; e.print
    end
  end
end
