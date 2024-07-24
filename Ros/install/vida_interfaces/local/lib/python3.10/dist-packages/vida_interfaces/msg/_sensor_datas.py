# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vida_interfaces:msg/SensorDatas.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SensorDatas(type):
    """Metaclass of message 'SensorDatas'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vida_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vida_interfaces.msg.SensorDatas')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__sensor_datas
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__sensor_datas
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__sensor_datas
            cls._TYPE_SUPPORT = module.type_support_msg__msg__sensor_datas
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__sensor_datas

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SensorDatas(metaclass=Metaclass_SensorDatas):
    """Message class 'SensorDatas'."""

    __slots__ = [
        '_left_pulses',
        '_right_pulses',
        '_back_pulses',
        '_steering',
    ]

    _fields_and_field_types = {
        'left_pulses': 'int64',
        'right_pulses': 'int64',
        'back_pulses': 'int64',
        'steering': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.left_pulses = kwargs.get('left_pulses', int())
        self.right_pulses = kwargs.get('right_pulses', int())
        self.back_pulses = kwargs.get('back_pulses', int())
        self.steering = kwargs.get('steering', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.left_pulses != other.left_pulses:
            return False
        if self.right_pulses != other.right_pulses:
            return False
        if self.back_pulses != other.back_pulses:
            return False
        if self.steering != other.steering:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def left_pulses(self):
        """Message field 'left_pulses'."""
        return self._left_pulses

    @left_pulses.setter
    def left_pulses(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'left_pulses' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'left_pulses' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._left_pulses = value

    @builtins.property
    def right_pulses(self):
        """Message field 'right_pulses'."""
        return self._right_pulses

    @right_pulses.setter
    def right_pulses(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'right_pulses' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'right_pulses' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._right_pulses = value

    @builtins.property
    def back_pulses(self):
        """Message field 'back_pulses'."""
        return self._back_pulses

    @back_pulses.setter
    def back_pulses(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'back_pulses' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'back_pulses' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._back_pulses = value

    @builtins.property
    def steering(self):
        """Message field 'steering'."""
        return self._steering

    @steering.setter
    def steering(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'steering' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'steering' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._steering = value
