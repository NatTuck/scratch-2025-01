
import sys
import inspect
import pyglet
from PIL import Image

if __name__ == '__main__':
    print("This is a library.")
    sys.exit(1)

def run():
    app = sys.modules['__main__']
    import sim.defaults

    callbacks = {}
    for name in ['config', 'init', 'draw', 'tick',
                 'key_press', 'mouse_click']:
        if name in app.__dict__:
            callbacks[name] = getattr(app, name)
        else:
            callbacks[name] = getattr(defaults, name)

    config = callbacks['config']()

    state = callbacks['init']()
    
    window = pyglet.window.Window(
        caption=config['title'],
        width=config['width'],
        height=config['height'],
        resizable=config['resizable'])

    keys = set()
    
    @window.event
    def on_draw():
        window.clear()
        scene = convert_image(callbacks['draw'](state))
        sp = pyglet.sprite.Sprite(scene, x=0, y=0)
        sp.draw()

        
    @window.event
    def on_key_press(key, _mods):
        nonlocal keys
        keys.add(pyglet.window.key.symbol_string(key).lower())

        
    @window.event
    def on_key_release(key, _mods):
        nonlocal keys
        keys.remove(pyglet.window.key.symbol_string(key).lower())

            
    @window.event
    def on_mouse_press(x, y, _btn, _mods):
        nonlocal state
        hh = config['height']
        state = callbacks['mouse_click'](state, x, hh - y, "left")
        
        
    def tick(dt):
        nonlocal state, keys
        for key in keys:
            state = callbacks['key_press'](state, key)
        if (nparms(callbacks['tick']) == 1):
            state = callbacks['tick'](state)
        else:
            state = callbacks['tick'](state, dt)


    if 'tick' in app.__dict__:
        pyglet.clock.schedule_interval(tick, 1 / 30.0)

        
    pyglet.app.run()


def nparms(fn):
    return len(inspect.signature(fn).parameters)
            

def convert_image(im):
    data = im.convert('RGBA').transpose(Image.Transpose.FLIP_TOP_BOTTOM).tobytes()
    tx = pyglet.image.ImageData(im.width, im.height, 'RGBA', data)
    return tx
