""" Node is defined as
class node:
  def __init__(self, data):
      self.data = data
      self.left = None
      self.right = None
"""
def check_binary_search_tree_(root):
    visited=[]
    queue=[] #storing: items 
    if root is None: return False
    queue.append({'node':root, 'lower_limit':None, 'upper_limit':None})
    while queue: #O(n)
        item = queue[0]
        queue.remove(item)
        curr, lower_limit, upper_limit = item['node'], item['lower_limit'], item['upper_limit'] 
        visited.append(curr)
        
        if (lower_limit and curr.data <= lower_limit) or (upper_limit and curr.data >= upper_limit):
            return False
        
        if curr.left is not None:
            if curr.left.data is None or curr.data <= curr.left.data or curr.left in visited:
                return False
            queue.append({'node':curr.left, 
                            'lower_limit':lower_limit, 
                            'upper_limit':curr.data})
        
        if curr.right is not None:
            if curr.right.data is None or curr.data >= curr.right.data or curr.right in visited:
                return False            
            queue.append({'node':curr.right,
                            'lower_limit':curr.data,
                            'upper_limit':upper_limit})
    return True